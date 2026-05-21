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

function getCart(req) {
  if (!req.session.cart) {
    req.session.cart = {
      merchantId: "",
      items: {}, // { [foodId]: quantity }
      lastAdd: { key: "", at: 0 },
    };
  }
  if (!req.session.cart.items || typeof req.session.cart.items !== "object") {
    req.session.cart.items = {};
  }
  if (!req.session.cart.lastAdd || typeof req.session.cart.lastAdd !== "object") {
    req.session.cart.lastAdd = { key: "", at: 0 };
  }
  return req.session.cart;
}

function cartItemCount(cart) {
  return Object.values(cart.items || {}).reduce((sum, qty) => sum + (Number(qty) || 0), 0);
}

async function buildCheckoutSummary(cart) {
  const merchantId = cart.merchantId;
  const foodIds = Object.keys(cart.items || {}).filter(Boolean);

  if (!merchantId || foodIds.length === 0) {
    return {
      merchant: null,
      items: [],
      total: 0,
    };
  }

  const foods = await FoodItem.find({ _id: { $in: foodIds }, merchant: merchantId });
  const foodById = new Map(foods.map((f) => [String(f._id), f]));

  const lines = [];
  let total = 0;

  for (const foodId of foodIds) {
    const food = foodById.get(String(foodId));
    if (!food) continue;

    const quantity = Math.max(0, parseInt(cart.items[foodId], 10) || 0);
    if (quantity <= 0) continue;

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
    });

    total += lineTotal;
  }

  const merchant = await User.findById(merchantId).select("username");

  return {
    merchant,
    items: lines,
    total,
  };
}

// Add to cart (student only)
router.post("/cart/add", isLoggedIn, checkRole("student"), async (req, res) => {
  try {
    const { foodId, merchantId } = req.body;
    const rawQty = req.body.quantity;

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

    // Enforce a single-merchant cart (simplest/cleanest checkout)
    if (cart.merchantId && String(cart.merchantId) !== String(merchantId)) {
      cart.merchantId = String(merchantId);
      cart.items = {};
      cart.lastAdd = { key: "", at: 0 };
    }

    cart.merchantId = String(merchantId);
    const prev = parseInt(cart.items[String(foodId)], 10) || 0;
    cart.items[String(foodId)] = Math.min(99, prev + quantity);
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
    const cart = getCart(req);

    if (!foodId) {
      return res.redirect(`/orders/checkout?error=${encodeURIComponent("Invalid item")}`);
    }

    const qty = parseInt(quantity, 10);
    if (!Number.isFinite(qty) || qty <= 0) {
      delete cart.items[String(foodId)];
    } else {
      cart.items[String(foodId)] = Math.min(99, qty);
    }

    if (cartItemCount(cart) === 0) {
      cart.merchantId = "";
      cart.items = {};
    }

    return res.redirect(`/orders/checkout?success=${encodeURIComponent("Cart updated")}`);
  } catch (err) {
    console.log(err);
    return res.redirect(`/orders/checkout?error=${encodeURIComponent("Cart update failed")}`);
  }
});

router.post("/cart/clear", isLoggedIn, checkRole("student"), (req, res) => {
  const cart = getCart(req);
  cart.merchantId = "";
  cart.items = {};
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

    if (!summary.items.length || !cart.merchantId) {
      return res.redirect(`/shops?info=${encodeURIComponent("Your cart is empty")}`);
    }

    const order = new Order({
      student: req.session.user.id,
      studentName: req.session.user.username,
      merchant: cart.merchantId,
      items: summary.items.map((line) => ({
        food: line.foodId,
        foodName: line.name,
        unitPrice: line.unitPrice.toFixed(2),
        quantity: line.quantity,
      })),
      totalPrice: summary.total.toFixed(2),
      fulfillmentType: "pickup",
      paymentMethod: "pay_on_pickup",
      status: "Pending",
    });

    await order.save();

    // clear cart
    cart.merchantId = "";
    cart.items = {};

    return res.redirect(`/orders?success=${encodeURIComponent("Order placed (pay on pickup)")}`);
  } catch (err) {
    console.log(err);
    return res.redirect(`/orders/checkout?error=${encodeURIComponent("Checkout failed")}`);
  }
});

// Orders list (role-based)
router.get("/", isLoggedIn, async (req, res) => {
  try {
    const user = req.session.user;
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
      return res.status(403).send("Access denied");
    }

    const ordersForView = (orders || []).map((o) => ({
      ...o,
      totalPriceText: moneyText(o.totalPrice),
    }));

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

      const allowedStatuses = new Set(["Pending", "Ready", "Completed"]);
      if (!allowedStatuses.has(nextStatus)) {
        return res.redirect(`/orders?error=${encodeURIComponent("Invalid status")}`);
      }

      const order = await Order.findById(orderId).select("merchant status");
      if (!order) {
        return res.redirect(`/orders?error=${encodeURIComponent("Order not found")}`);
      }

      if (String(order.status || "") === "Cancelled") {
        return res.redirect(`/orders?error=${encodeURIComponent("Cancelled orders cannot be updated")}`);
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
