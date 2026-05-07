const express = require("express");
const router = express.Router();
const isLoggedIn = require("../middleware/authMiddleware");
const FoodItem = require("../models/FoodItem");

// View Menu
router.get("/", isLoggedIn, async (req, res) => {
  try {
    const search = req.query.search || "";
    const category = req.query.category || "";

    let query = {
      availability: true,
      name: { $regex: search, $options: "i" }
    };

    // apply category filter
    if (category) {
      query.category = category;
    }

    const foods = await FoodItem.find(query);

    res.render("customer/menu", {
      foods,
      search,
      category,
      merchantId: "",
    });

  } catch (err) {
    console.log(err);
    res.send("Error loading menu");
  }
});

// View Menu for a Specific Merchant
router.get("/:merchantId", isLoggedIn, async (req, res) => {
  try {
    const { merchantId } = req.params;
    const search = req.query.search || "";
    const category = req.query.category || "";

    let query = {
      availability: true,
      merchant: merchantId,
      name: { $regex: search, $options: "i" },
    };

    if (category) {
      query.category = category;
    }

    const foods = await FoodItem.find(query);

    return res.render("customer/menu", {
      foods,
      search,
      category,
      merchantId,
    });
  } catch (err) {
    console.log(err);
    return res.send("Error loading menu");
  }
});

module.exports = router;