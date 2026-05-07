const express = require("express");
const router = express.Router();
const isLoggedIn = require("../middleware/authMiddleware");
const checkRole = require("../middleware/roleMiddleware");
const FoodItem = require("../models/FoodItem");

// VIEW MENU
router.get("/", async (req, res) => {
  try {
    const foods = await FoodItem.find();

    res.render("menu", { foods });
  } catch (err) {
    console.log(err);
    res.send("Error loading menu");
  }
});

// ADD FOOD PAGE
router.get("/add", isLoggedIn, checkRole("merchant", "admin"), (req, res) => {
  res.render("addFood");
});

// ADD FOOD FUNCTION
router.post("/add", isLoggedIn, checkRole("merchant", "admin"), async (req, res) => {
  try {
    const { name, price, category, description } = req.body;

    const newFood = new FoodItem({
        name,
        price,
        category,
        description,
        merchant: req.session.user.id,
    });

    await newFood.save();

    res.redirect("/foods");
  } catch (err) {
    console.log(err);
    res.send("Error adding food");
  }
});

module.exports = router;