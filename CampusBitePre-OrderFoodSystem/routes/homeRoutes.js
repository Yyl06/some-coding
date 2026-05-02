const express = require("express");
const router = express.Router();
const isLoggedIn = require("../middleware/authMiddleware");

router.get("/menu", isLoggedIn, (req, res) => {
  res.send("Food Menu");
});

module.exports = router;