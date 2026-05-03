const express = require("express");
const router = express.Router();

const isLoggedIn = require("../middleware/authMiddleware");

// Homepage
router.get("/", (req, res) => {
  res.render("index");
});

module.exports = router;