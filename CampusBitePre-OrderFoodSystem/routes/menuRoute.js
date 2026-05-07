const express = require("express");
const router = express.Router();
const isLoggedIn = require("../middleware/authMiddleware");
const checkRole = require("../middleware/roleMiddleware");
const FoodItem = require("../models/FoodItem");

// VIEW MENU
router.get("/", async (req, res) => {
  try {
    const search = req.query.search || "";

    const foods = await FoodItem.find({
      name: { $regex: search, $options: "i" }
    });

    res.render("menu", {
      foods,
      search
    });

  } catch (err) {
    console.log(err);
    res.send("Error loading menu");
  }
});

module.exports = router;