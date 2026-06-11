const express = require("express");
const router = express.Router();
const isLoggedIn = require("../middleware/authMiddleware");
const checkRole = require("../middleware/roleMiddleware");
const FoodItem = require("../models/FoodItem");
const Order = require("../models/Order");
const User = require("../models/User");


function decimalToNumber(value) {
  if (value == null) return 0;
  if (typeof value === "number") return Number.isFinite(value) ? value : 0;
  if (typeof value === "string") {
    const n = Number(value);
    return Number.isFinite(n) ? n : 0;
  }
  if (typeof value === "object" && value.$numberDecimal) {
    const n = Number(value.$numberDecimal);
    return Number.isFinite(n) ? n : 0;
  }
  if (typeof value?.toString === "function") {
    const n = Number(value.toString());
    return Number.isFinite(n) ? n : 0;
  }
  return 0;
}

function moneyText(value) {
  const n = Math.max(0, decimalToNumber(value));
  return n.toFixed(2);
}

function normalizeRemark(value) {
  const text = String(value || "").trim();
  return text ? text.slice(0, 200) : "";
}

function startOfDay(date) {
  const d = new Date(date);
  d.setHours(0, 0, 0, 0);
  return d;
}

function endOfDay(date) {
  const d = new Date(date);
  d.setHours(23, 59, 59, 999);
  return d;
}

function todayDateValue(timeZone = "Asia/Kuala_Lumpur") {
  const parts = new Intl.DateTimeFormat("en-CA", {
    timeZone,
    year: "numeric",
    month: "2-digit",
    day: "2-digit",
  }).formatToParts(new Date());

  const values = Object.fromEntries(parts.map((part) => [part.type, part.value]));
  return `${values.year}-${values.month}-${values.day}`;
}

function parseReportDate(value, timeZoneOffset = "+08:00") {
  const raw = String(value || "").trim();
  const todayValue = todayDateValue();
  const requestedDateValue = /^\d{4}-\d{2}-\d{2}$/.test(raw) ? raw : todayValue;
  const dateValue = requestedDateValue > todayValue ? todayValue : requestedDateValue;

  return {
    dateValue,
    todayValue,
    day: new Date(`${dateValue}T00:00:00${timeZoneOffset}`),
    dayEnd: new Date(`${dateValue}T23:59:59.999${timeZoneOffset}`),
  };
}

function getCart(req) {
  if (!req.session.cart) {
    req.session.cart = {
      merchantId: "",
      items: {}, // { [foodId]: { quantity, remark, merchantId } }
      lastAdd: { key: "", at: 0 },
    };
  }
  if (!req.session.cart.items || typeof req.session.cart.items !== "object") {
    req.session.cart.items = {};
  }
  if (!req.session.cart.lastAdd || typeof req.session.cart.lastAdd !== "object") {
    req.session.cart.lastAdd = { key: "", at: 0 };
  }

  Object.keys(req.session.cart.items).forEach((foodId) => {
    const entry = req.session.cart.items[foodId];
    if (entry && typeof entry === "object" && !Array.isArray(entry)) {
      const quantity = Math.max(0, parseInt(entry.quantity, 10) || 0);
      const remark = normalizeRemark(entry.remark);
      const merchantId = String(entry.merchantId || req.session.cart.merchantId || "");

      if (quantity <= 0) {
        delete req.session.cart.items[foodId];
        return;
      }

      req.session.cart.items[foodId] = { quantity, remark, merchantId };
      return;
    }

    const quantity = Math.max(0, parseInt(entry, 10) || 0);
    if (quantity <= 0) {
      delete req.session.cart.items[foodId];
      return;
    }

    req.session.cart.items[foodId] = {
      quantity,
      remark: "",
      merchantId: String(req.session.cart.merchantId || ""),
    };
  });

  return req.session.cart;
}

function cartItemCount(cart) {
  return Object.values(cart.items || {}).reduce((sum, item) => {
    if (item && typeof item === "object") {
      return sum + (Number(item.quantity) || 0);
    }
    return sum + (Number(item) || 0);
  }, 0);
}

async function buildCheckoutSummary(cart) {
  const foodIds = Object.keys(cart.items || {}).filter(Boolean);

  if (foodIds.length === 0) {
    return {
      merchant: null,
      items: [],
      groups: [],
      total: 0,
    };
  }

  const foods = await FoodItem.find({ _id: { $in: foodIds } });
  const foodById = new Map(foods.map((f) => [String(f._id), f]));

  const lines = [];
  let total = 0;

  for (const foodId of foodIds) {
    const food = foodById.get(String(foodId));
    if (!food) continue;

    const cartItem = cart.items[foodId];
    const quantity = Math.max(
      0,
      parseInt(cartItem && typeof cartItem === "object" ? cartItem.quantity : cartItem, 10) || 0
    );
    if (quantity <= 0) continue;

    const remark = normalizeRemark(cartItem && typeof cartItem === "object" ? cartItem.remark : "");
    const merchantId = String(food.merchant);

    const unit = Math.max(0, decimalToNumber(food.price));
    const lineTotal = unit * quantity;

    lines.push({
      foodId: String(food._id),
      name: food.name,
      category: food.category,
      image: food.image || "",
      unitPrice: unit,
      quantity,
      lineTotal,
      remark,
      merchantId,
    });

    total += lineTotal;
  }

  const merchantIds = [...new Set(lines.map((line) => String(line.merchantId)).filter(Boolean))];
  const merchants = await User.find({ _id: { $in: merchantIds } }).select("username").lean();
  const merchantById = new Map(merchants.map((m) => [String(m._id), m]));
  const groupsByMerchant = new Map();

  for (const line of lines) {
    const key = String(line.merchantId);
    const merchant = merchantById.get(key) || { _id: key, username: "Merchant" };

    if (!groupsByMerchant.has(key)) {
      groupsByMerchant.set(key, {
        merchant,
        items: [],
        total: 0,
      });
    }

    const group = groupsByMerchant.get(key);
    group.items.push(line);
    group.total += line.lineTotal;
  }

  const groups = [...groupsByMerchant.values()];

  return {
    merchant: groups.length === 1 ? groups[0].merchant : null,
    items: lines,
    groups,
    total,
  };
}

async function loadOrdersForUser(user) {
  let orders = [];

  if (user.role === "student") {
    orders = await Order.find({ student: user.id })
      .sort({ createdAt: -1 })
      .populate("merchant", "username")
      .lean();
  } else if (user.role === "merchant") {
    orders = await Order.find({ merchant: user.id })
      .sort({ createdAt: -1 })
      .populate("student", "username")
      .lean();
  } else if (user.role === "admin") {
    orders = await Order.find({})
      .sort({ createdAt: -1 })
      .populate("student", "username")
      .populate("merchant", "username")
      .lean();
  } else {
    return [];
  }

  return (orders || []).map((o) => ({
    ...o,
    totalPriceText: moneyText(o.totalPrice),
  }));
}

// Add to cart (student only)
router.post("/cart/add", isLoggedIn, checkRole("student"), async (req, res) => {
  try {
    const { foodId, merchantId } = req.body;
    const rawQty = req.body.quantity;
    const remark = normalizeRemark(req.body.remark);

    if (!foodId || !merchantId) {
      return res.redirect(`/shops?error=${encodeURIComponent("Invalid item")}`);
    }

    const qtyParsed = parseInt(rawQty, 10);
    if (!Number.isFinite(qtyParsed) || qtyParsed <= 0) {
      return res.redirect(
        `/menu/${merchantId}?error=${encodeURIComponent("Invalid quantity")}`
      );
    }
    const quantity = Math.min(99, qtyParsed);

    const food = await FoodItem.findById(foodId).select("merchant availability");
    if (!food) return res.redirect(`/shops?error=${encodeURIComponent("Food not found")}`);
    if (!food.availability) {
      return res.redirect(
        `/menu/${merchantId}?error=${encodeURIComponent("This item is unavailable")}`
      );
    }

    if (String(food.merchant) !== String(merchantId)) {
      return res.redirect(`/shops?error=${encodeURIComponent("Invalid merchant")}`);
    }

    const cart = getCart(req);

    // Basic double-click / duplicate POST guard (same item within a short window)
    const addKey = `${String(merchantId)}:${String(foodId)}`;
    const now = Date.now();
    const last = cart.lastAdd || { key: "", at: 0 };
    if (last.key === addKey && now - (Number(last.at) || 0) < 800) {
      return res.redirect(
        `/menu/${merchantId}?info=${encodeURIComponent("Item already added")}`
      );
    }

    cart.merchantId = String(merchantId);
    const existing = cart.items[String(foodId)];
    const prevQuantity = parseInt(existing && typeof existing === "object" ? existing.quantity : existing, 10) || 0;
    const existingRemark = normalizeRemark(existing && typeof existing === "object" ? existing.remark : "");
    cart.items[String(foodId)] = {
      quantity: Math.min(99, prevQuantity + quantity),
      remark: remark || existingRemark,
      merchantId: String(merchantId),
    };
    cart.lastAdd = { key: addKey, at: now };

    return res.redirect(
      `/menu/${merchantId}?success=${encodeURIComponent("Added to cart")}`
    );
  } catch (err) {
    console.log(err);
    return res.redirect(`/shops?error=${encodeURIComponent("Failed to add to cart")}`);
  }
});

router.post("/cart/update", isLoggedIn, checkRole("student"), async (req, res) => {
  try {
    const { foodId, quantity } = req.body;
    const hasRemarkField = Object.prototype.hasOwnProperty.call(req.body, "remark");
    const remark = hasRemarkField ? normalizeRemark(req.body.remark) : null;
    const cart = getCart(req);

    if (!foodId) {
      return res.redirect(`/orders/checkout?error=${encodeURIComponent("Invalid item")}`);
    }

    const qty = parseInt(quantity, 10);
    if (!Number.isFinite(qty) || qty <= 0) {
      delete cart.items[String(foodId)];
    } else {
      const existing = cart.items[String(foodId)];
      const existingRemark = normalizeRemark(existing && typeof existing === "object" ? existing.remark : "");
      const existingMerchantId = String(existing && typeof existing === "object" ? existing.merchantId || "" : "");
      cart.items[String(foodId)] = {
        quantity: Math.min(99, qty),
        remark: remark === null ? existingRemark : remark,
        merchantId: existingMerchantId,
      };
    }

    if (cartItemCount(cart) === 0) {
      cart.merchantId = "";
      cart.items = {};
      cart.lastAdd = { key: "", at: 0 };
    }

    return res.redirect(`/orders/checkout?success=${encodeURIComponent("Cart updated")}`);
  } catch (err) {
    console.log(err);
    return res.redirect(`/orders/checkout?error=${encodeURIComponent("Cart update failed")}`);
  }
});

router.post("/cart/delete", isLoggedIn, checkRole("student"), (req, res) => {
  const { foodId } = req.body;
  const cart = getCart(req);

  if (!foodId) {
    return res.redirect(`/orders/checkout?error=${encodeURIComponent("Invalid item")}`);
  }

  delete cart.items[String(foodId)];

  if (cartItemCount(cart) === 0) {
    cart.merchantId = "";
    cart.items = {};
    cart.lastAdd = { key: "", at: 0 };
  }

  return res.redirect(`/orders/checkout?success=${encodeURIComponent("Item removed")}`);
});

router.post("/cart/clear", isLoggedIn, checkRole("student"), (req, res) => {
  const cart = getCart(req);
  cart.merchantId = "";
  cart.items = {};
  cart.lastAdd = { key: "", at: 0 };
  return res.redirect(`/shops?info=${encodeURIComponent("Cart cleared")}`);
});

// Checkout page (pickup + pay on pickup)
router.get("/checkout", isLoggedIn, checkRole("student"), async (req, res) => {
  try {
    const cart = getCart(req);
    const summary = await buildCheckoutSummary(cart);

    if (!summary.items.length) {
      return res.redirect(`/shops?info=${encodeURIComponent("Your cart is empty")}`);
    }

    return res.render("customer/checkout", {
      user: req.session.user,
      merchant: summary.merchant,
      items: summary.items,
      groups: summary.groups,
      total: summary.total,
    });
  } catch (err) {
    console.log(err);
    return res.send("Error loading checkout");
  }
});

router.post("/checkout", isLoggedIn, checkRole("student"), async (req, res) => {
  try {
    const cart = getCart(req);
    const summary = await buildCheckoutSummary(cart);

    if (!summary.groups.length) {
      return res.redirect(`/shops?info=${encodeURIComponent("Your cart is empty")}`);
    }

    const orders = summary.groups.map((group) => new Order({
      student: req.session.user.id,
      studentName: req.session.user.username,
      merchant: group.merchant._id,
      items: group.items.map((line) => ({
        food: line.foodId,
        foodName: line.name,
        unitPrice: line.unitPrice.toFixed(2),
        quantity: line.quantity,
        remark: line.remark || "",
      })),
      totalPrice: group.total.toFixed(2),
      fulfillmentType: "pickup",
      paymentMethod: "pay_on_pickup",
      status: "Pending",
    }));

    await Promise.all(orders.map((order) => order.save()));

    // clear cart
    cart.merchantId = "";
    cart.items = {};
    cart.lastAdd = { key: "", at: 0 };

    const message =
      orders.length === 1
        ? "Order placed (pay on pickup)"
        : `${orders.length} orders placed (pay on pickup)`;

    return res.redirect(`/orders?success=${encodeURIComponent(message)}`);
  } catch (err) {
    console.log(err);
    return res.redirect(`/orders/checkout?error=${encodeURIComponent("Checkout failed")}`);
  }
});

// Orders list JSON (auto-refresh)
router.get("/list", isLoggedIn, async (req, res) => {
  try {
    const user = req.session.user;
    const ordersForView = await loadOrdersForUser(user);

    const orders = (ordersForView || []).map((o) => ({
      id: String(o._id),
      status: String(o.status || "Pending"),
      createdAt: o.createdAt ? new Date(o.createdAt).toISOString() : "",
      totalPriceText: o.totalPriceText || "",
      merchant: o.merchant && o.merchant.username ? o.merchant.username : "",
      student:
        o.student && o.student.username
          ? o.student.username
          : (o.studentName || ""),
      items: (o.items || []).map((it) => ({
        foodName: it.foodName || "",
        quantity: Number(it.quantity) || 0,
        remark: it.remark || "",
      })),
    }));

    return res.json({ role: user.role, orders });
  } catch (err) {
    console.log(err);
    return res.status(500).json({ role: "", orders: [] });
  }
});

// Customer notifications (polling endpoint)
router.get("/notifications", isLoggedIn, checkRole("student"), async (req, res) => {
  try {
    const user = req.session.user;
    const orders = await Order.find({ student: user.id })
      .sort({ createdAt: -1 })
      .limit(20)
      .populate("merchant", "username")
      .lean();

    const data = (orders || []).map((o) => ({
      id: String(o._id),
      status: String(o.status || "Pending"),
      merchant: o.merchant && o.merchant.username ? o.merchant.username : "",
      createdAt: o.createdAt ? new Date(o.createdAt).toISOString() : "",
    }));

    return res.json({ orders: data });
  } catch (err) {
    console.log(err);
    return res.status(500).json({ orders: [] });
  }
});

// Merchant notifications (polling endpoint)
router.get("/notifications/merchant", isLoggedIn, checkRole("merchant"), async (req, res) => {
  try {
    const user = req.session.user;
    const orders = await Order.find({ merchant: user.id })
      .sort({ createdAt: -1 })
      .limit(30)
      .populate("student", "username")
      .lean();

    const data = (orders || []).map((o) => ({
      id: String(o._id),
      status: String(o.status || "Pending"),
      student: o.student && o.student.username ? o.student.username : (o.studentName || ""),
      createdAt: o.createdAt ? new Date(o.createdAt).toISOString() : "",
    }));

    return res.json({ orders: data });
  } catch (err) {
    console.log(err);
    return res.status(500).json({ orders: [] });
  }
});

// Merchant daily report
router.get("/reports/daily", isLoggedIn, checkRole("merchant", "admin"), async (req, res) => {
  try {
    const user = req.session.user;
    const day = startOfDay(new Date());
    const dayEnd = endOfDay(new Date());

    const match =
      user.role === "admin"
        ? { createdAt: { $gte: day, $lte: dayEnd } }
        : { merchant: user.id, createdAt: { $gte: day, $lte: dayEnd } };

    const orders = await Order.find(match)
      .sort({ createdAt: -1 })
      .populate("student", "username")
      .populate("merchant", "username")
      .lean();

    const statusCounts = (orders || []).reduce((acc, o) => {
      const key = String(o.status || "Pending");
      acc[key] = (acc[key] || 0) + 1;
      return acc;
    }, {});

    const totalRevenue = (orders || []).reduce(
      (sum, o) => sum + decimalToNumber(o.totalPrice),
      0
    );

    const ordersForView = (orders || []).map((o) => ({
      ...o,
      totalPriceText: moneyText(o.totalPrice),
    }));

    return res.render("merchant/dailyReport", {
      user,
      day,
      orders: ordersForView,
      statusCounts,
      totalRevenue: totalRevenue.toFixed(2),
    });
  } catch (err) {
    console.log(err);
    return res.send("Error loading daily report");
  }
});

// Admin reports
router.get("/reports/admin", isLoggedIn, checkRole("admin"), async (req, res) => {
  try {
    const { dateValue, todayValue, day, dayEnd } = parseReportDate(req.query.date);
    const dateMatch = { createdAt: { $gte: day, $lte: dayEnd } };

    const [
      totalOrders,
      ordersForDate,
      totalUsers,
      totalMerchants,
      totalStudents,
      totalRevenueRaw,
      revenueForDateRaw,
    ] = await Promise.all([
      Order.countDocuments({}),
      Order.countDocuments(dateMatch),
      User.countDocuments({}),
      User.countDocuments({ role: "merchant" }),
      User.countDocuments({ role: "student" }),
      Order.find({}).select("totalPrice").lean(),
      Order.find(dateMatch).select("totalPrice").lean(),
    ]);

    const totalRevenue = (totalRevenueRaw || []).reduce(
      (sum, o) => sum + decimalToNumber(o.totalPrice),
      0
    );
    const revenueForDate = (revenueForDateRaw || []).reduce(
      (sum, o) => sum + decimalToNumber(o.totalPrice),
      0
    );

    return res.render("admin/reports", {
      day,
      dateValue,
      todayValue,
      totalOrders,
      ordersToday: ordersForDate,
      ordersForDate,
      totalUsers,
      totalMerchants,
      totalStudents,
      totalRevenue: totalRevenue.toFixed(2),
      revenueToday: revenueForDate.toFixed(2),
      revenueForDate: revenueForDate.toFixed(2),
    });
  } catch (err) {
    console.log(err);
    return res.send("Error loading admin reports");
  }
});

// Orders list (role-based)
router.get("/", isLoggedIn, async (req, res) => {
  try {
    const user = req.session.user;
    const ordersForView = await loadOrdersForUser(user);

    if (!ordersForView) {
      return res.status(403).send("Access denied");
    }

    return res.render("orders/index", { user, orders: ordersForView });
  } catch (err) {
    console.log(err);
    return res.send("Error loading orders");
  }
});

// Student marks order as completed after pickup
router.post(
  "/:orderId/complete",
  isLoggedIn,
  checkRole("student"),
  async (req, res) => {
    try {
      const user = req.session.user;
      const { orderId } = req.params;

      const order = await Order.findById(orderId).select("student status");
      if (!order) {
        return res.redirect(`/orders?error=${encodeURIComponent("Order not found")}`);
      }

      if (String(order.student) !== String(user.id)) {
        return res.status(403).send("Access denied");
      }

      if (String(order.status || "") === "Cancelled") {
        return res.redirect(`/orders?error=${encodeURIComponent("Cancelled orders cannot be completed")}`);
      }

      // Simplest rule: only allow completion once merchant marks it Ready.
      if (String(order.status || "") !== "Ready") {
        return res.redirect(
          `/orders?error=${encodeURIComponent("Order must be Ready before completing")}`
        );
      }

      order.status = "Completed";
      await order.save();

      return res.redirect(`/orders?success=${encodeURIComponent("Order completed")}`);
    } catch (err) {
      console.log(err);
      return res.redirect(`/orders?error=${encodeURIComponent("Failed to complete order")}`);
    }
  }
);

// Student cancels order (only while Pending)
router.post(
  "/:orderId/cancel",
  isLoggedIn,
  checkRole("student"),
  async (req, res) => {
    try {
      const user = req.session.user;
      const { orderId } = req.params;

      const order = await Order.findById(orderId).select("student status");
      if (!order) {
        return res.redirect(`/orders?error=${encodeURIComponent("Order not found")}`);
      }

      if (String(order.student) !== String(user.id)) {
        return res.status(403).send("Access denied");
      }

      if (String(order.status || "") !== "Pending") {
        return res.redirect(
          `/orders?error=${encodeURIComponent("Only Pending orders can be cancelled")}`
        );
      }

      order.status = "Cancelled";
      await order.save();

      return res.redirect(`/orders?success=${encodeURIComponent("Order cancelled")}`);
    } catch (err) {
      console.log(err);
      return res.redirect(`/orders?error=${encodeURIComponent("Failed to cancel order")}`);
    }
  }
);

// Update order status (merchant/admin)
router.post(
  "/:orderId/status",
  isLoggedIn,
  checkRole("merchant", "admin"),
  async (req, res) => {
    try {
      const user = req.session.user;
      const { orderId } = req.params;
      const nextStatus = String(req.body.status || "").trim();

      const allowedStatuses = new Set([
        "Pending",
        "Confirmed",
        "Ready",
        "Completed",
        "Rejected",
      ]);
      if (!allowedStatuses.has(nextStatus)) {
        return res.redirect(`/orders?error=${encodeURIComponent("Invalid status")}`);
      }

      const order = await Order.findById(orderId).select("merchant status");
      if (!order) {
        return res.redirect(`/orders?error=${encodeURIComponent("Order not found")}`);
      }

      if (String(order.status || "") === "Cancelled" || String(order.status || "") === "Rejected") {
        return res.redirect(`/orders?error=${encodeURIComponent("Cancelled or Rejected orders cannot be updated")}`);
      }

      if (user.role === "merchant" && String(order.merchant) !== String(user.id)) {
        return res.status(403).send("Access denied");
      }

      order.status = nextStatus;
      await order.save();

      return res.redirect(`/orders?success=${encodeURIComponent("Order status updated")}`);
    } catch (err) {
      console.log(err);
      return res.redirect(`/orders?error=${encodeURIComponent("Failed to update status")}`);
    }
  }
);

module.exports = router;
