const express = require("express");
const router = express.Router();
const isLoggedIn = require("../middleware/authMiddleware");
const checkRole = require("../middleware/roleMiddleware");
const FoodItem = require("../models/FoodItem");

router.get("/profile", isLoggedIn, checkRole("student", "merchant"), (req, res) => {
  if (!req.session.user) {
    return res.redirect("/auth/login");
  }

  res.render("auth/profile", {
    user: req.session.user,
  });
});