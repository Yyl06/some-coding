const express = require("express");
const router = express.Router();
const isLoggedIn = require("../middleware/authMiddleware");
const checkRole = require("../middleware/roleMiddleware");
const FoodItem = require("../models/FoodItem");
const { uploadFoodImage } = require("../middleware/uploadMiddleware");
const { Decimal128 } = require("mongodb");

function canManageFood(req, food) {
  const user = req.session.user;
  if (!user) return false;
  if (user.role === "admin") return true;
  return String(food.merchant) === String(user.id);
}

// Manage Foods (merchant/admin only)
router.get("/", isLoggedIn, checkRole("merchant", "admin"), async (req, res) => {
  try {
    const user = req.session.user;
    const foods =
      user.role === "admin"
        ? await FoodItem.find({}).populate("merchant", "username")
        : await FoodItem.find({ merchant: user.id });

    const success = typeof req.query.success === "string" ? req.query.success : null;
    return res.render("merchant/foods", { foods, user, success });
  } catch (err) {
    console.log(err);
    return res.send("Error loading foods");
  }
});

// Add Food Page
router.get("/add", isLoggedIn, checkRole("merchant", "admin"), (req, res) => {
  return res.render("merchant/editFood", {
    isEdit: false,
    food: {
      name: "",
      price: "",
      category: "",
      description: "",
    },
  });
});

// Add Food Function
router.post("/add", isLoggedIn, checkRole("merchant", "admin"), (req, res, next) => {
    uploadFoodImage.single("image")(req, res, (err) => {
      if (err) {
        console.log(err);
        return res.status(400).send(err.message || "Image upload failed");
      }
      return next();
    });
  },
  async (req, res) => {
  try {
    const { name, price, category, description } = req.body;

    if (!name || !price || !category) {
      return res.status(400).send("Required fields missing");
    }

    const newFood = new FoodItem({
        name,
        price: Decimal128(price),
        category,
        description,
        image: req.file ? `/images/foods/${req.file.filename}` : "",
        merchant: req.session.user.id,
    });

    await newFood.save();

    return res.redirect(`/foods?success=${encodeURIComponent("Food added")}`);
  } catch (err) {
    console.log(err);
    return res.send("Error adding food");
  }
});

// Edit Food Page
router.get("/:foodId/edit", isLoggedIn, checkRole("merchant", "admin"), async (req, res) => {
  try {
    const { foodId } = req.params;
    const food = await FoodItem.findById(foodId);

    if (!food) return res.status(404).send("Food not found");
    if (!canManageFood(req, food)) return res.status(403).send("Access denied");

    return res.render("merchant/editFood", { food, isEdit: true });
  } catch (err) {
    console.log(err);
    return res.send("Error loading food");
  }
});

// Edit Food Submit
router.post("/:foodId/edit", isLoggedIn, checkRole("merchant", "admin"), (req, res, next) => {
    uploadFoodImage.single("image")(req, res, (err) => {
      if (err) {
        console.log(err);
        return res.status(400).send(err.message || "Image upload failed");
      }
      return next();
    });
  },
  async (req, res) => {
  try {
    const { foodId } = req.params;
    const { name, price, category, description } = req.body;

    if (!name || !price || !category) {
      return res.status(400).send("Required fields missing");
    }

    const food = await FoodItem.findById(foodId);
    if (!food) return res.status(404).send("Food not found");
    if (!canManageFood(req, food)) return res.status(403).send("Access denied");

    food.name = name;
    food.price = new Decimal128(price);
    food.category = category;
    food.description = description;
    if (req.file) {
      food.image = `/images/foods/${req.file.filename}`;
    }
    await food.save();

    return res.redirect(`/foods?success=${encodeURIComponent("Food updated")}`);
  } catch (err) {
    console.log(err);
    return res.send("Error updating food");
  }
});

// Toggle Availability
router.post("/:foodId/toggle", isLoggedIn, checkRole("merchant", "admin"), async (req, res) => {
  try {
    const { foodId } = req.params;
    const food = await FoodItem.findById(foodId);

    if (!food) return res.status(404).send("Food not found");
    if (!canManageFood(req, food)) return res.status(403).send("Access denied");

    food.availability = !food.availability;
    await food.save();

    return res.redirect(
      `/foods?info=${encodeURIComponent(
        food.availability ? "Marked as available" : "Marked as unavailable"
      )}`
    );
  } catch (err) {
    console.log(err);
    return res.send("Error toggling availability");
  }
});

// Delete Food
router.post("/:foodId/delete", isLoggedIn, checkRole("merchant", "admin"), async (req, res) => {
  try {
    const { foodId } = req.params;
    const food = await FoodItem.findById(foodId);

    if (!food) return res.status(404).send("Food not found");
    if (!canManageFood(req, food)) return res.status(403).send("Access denied");

    await FoodItem.deleteOne({ _id: foodId });
    return res.redirect(`/foods?success=${encodeURIComponent("Food deleted")}`);
  } catch (err) {
    console.log(err);
    return res.send("Error deleting food");
  }
});

module.exports = router;