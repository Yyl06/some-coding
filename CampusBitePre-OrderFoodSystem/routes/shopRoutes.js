const express = require("express");
const router = express.Router();
const isLoggedIn = require("../middleware/authMiddleware");
const User = require("../models/User");

// Shop List
router.get("/", isLoggedIn, async (req, res) => {
  try {
    const search = req.query.search || "";

    const shops = await User.find({
      role: "merchant",
      username: { $regex: search, $options: "i" }
    });

    res.render("customer/restaurants", {
      shops,
      search
    });

  } catch (err) {
    console.log(err);
    res.send("Error loading shops");
  }
});

module.exports = router;