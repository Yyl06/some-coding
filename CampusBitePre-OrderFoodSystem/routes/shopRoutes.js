const express = require("express");
const router = express.Router();
const isLoggedIn = require("../middleware/authMiddleware");
const User = require("../models/User");

// Shop List
router.get("/", isLoggedIn, async (req, res) => {
  try {
    const search = req.query.search || "";
    const category = req.query.category || "";
    const type = req.query.type || "";

    const query = {
      role: "merchant",
      username: { $regex: search, $options: "i" },
    };

    if (type) {
      query.merchantType = type;
    }

    const shops = await User.find(query);

    res.render("customer/restaurants", {
      shops,
      search,
      category,
      type
    });

  } catch (err) {
    console.log(err);
    res.send("Error loading shops");
  }
});

module.exports = router;