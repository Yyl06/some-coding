const express = require("express");
const router = express.Router();
const isLoggedIn = require("../middleware/authMiddleware");
const FoodItem = require("../models/FoodItem");

function decimalToString(value) {
  if (value == null) return "";
  if (typeof value === "object" && value.$numberDecimal) return String(value.$numberDecimal);
  return String(value);
}

function priceTextFromFood(food) {
  const n = Number(decimalToString(food?.price));
  const safe = Number.isFinite(n) ? Math.max(0, n) : 0;
  return safe.toFixed(2);
}

// View Menu
router.get("/", isLoggedIn, async (req, res) => {
  try {
    // Force the intended flow: dashboard -> choose restaurant -> menu
    return res.redirect("/shops");

  } catch (err) {
    console.log(err);
    res.send("Error loading menu");
  }
});

// View Menu for a Specific Merchant
router.get("/:merchantId", isLoggedIn, async (req, res) => {
  try {
    const { merchantId } = req.params;
    const user = req.session.user;
    const search = req.query.search || "";
    const category = req.query.category || "";

    const cartCount = req.session?.cart?.items
      ? Object.values(req.session.cart.items).reduce(
          (sum, qty) => sum + (Number(qty) || 0),
          0
        )
      : 0;

    let query = {
      availability: true,
      merchant: merchantId,
      name: { $regex: search, $options: "i" },
    };

    if (category) {
      query.category = category;
    }

    const foodsRaw = await FoodItem.find(query).lean();
    const foods = (foodsRaw || []).map((f) => ({
      ...f,
      priceText: priceTextFromFood(f),
    }));

    const isMerchantViewingOwnMenu =
      user && user.role === "merchant" && String(user.id) === String(merchantId);
    const viewName = isMerchantViewingOwnMenu ? "merchant/merchantMenu" : "customer/customerMenu";

    return res.render(viewName, {
      foods,
      search,
      category,
      merchantId,
      cartCount,
    });
  } catch (err) {
    console.log(err);
    return res.send("Error loading menu");
  }
});

module.exports = router;