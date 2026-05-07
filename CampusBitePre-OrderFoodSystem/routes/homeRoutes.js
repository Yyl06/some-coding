const express = require("express");
const router = express.Router();
const isLoggedIn = require("../middleware/authMiddleware");

// Homepage
router.get("/", (req, res) => {
  if (req.session && req.session.user) {
    return res.redirect("/dashboard");
  }

  return res.render("index");
});

router.get("/dashboard", isLoggedIn, (req, res) => {
  const user = req.session.user;

  if (user.role === "merchant") {
    return res.render("merchant/dashboardMerchant", { user });
  }

  if (user.role === "admin") {
    return res.render("admin/dashboardAdmin", { user });
  }

  // default: student
  return res.render("customer/dashboardCustomer", { user });
});

module.exports = router;