const express = require("express");
const bcrypt = require("bcryptjs");

const router = express.Router();

const User = require("../models/User");

// ======================
// REGISTER PAGE
// ======================
router.get("/register", (req, res) => {
  res.render("auth/register");
});

// ======================
// REGISTER USER
// ======================
router.post("/register", async (req, res) => {
  try {
    const { username, email, password, role } = req.body;

    // Check existing user
    const existingUser = await User.findOne({ email });

    if (existingUser) {
      return res.send("Email already registered");
    }

    // Hash password
    const hashedPassword = await bcrypt.hash(password, 10);

    // Create user
    const newUser = new User({
      username,
      email,
      password: hashedPassword,
      role,
    });

    await newUser.save();

    res.send("Registration successful");
  } catch (err) {
    console.log(err);
    res.send("Registration failed");
  }
});

// ======================
// LOGIN PAGE
// ======================
router.get("/login", (req, res) => {
  res.render("auth/login");
});

// ======================
// LOGIN USER
// ======================
router.post("/login", async (req, res) => {
  try {
    const { email, password } = req.body;

    // Find user
    const user = await User.findOne({ email });

    if (!user) {
      return res.send("User not found");
    }

    // Compare password
    const isMatch = await bcrypt.compare(password, user.password);

    if (!isMatch) {
      return res.send("Invalid password");
    }

    // Store session
    req.session.user = {
      id: user._id,
      username: user.username,
      role: user.role,
    };

    res.send("Login successful");
  } catch (err) {
    console.log(err);
    res.send("Login failed");
  }
});

// ======================
// LOGOUT
// ======================
router.get("/logout", (req, res) => {
  req.session.destroy(() => {
    res.send("Logged out");
  });
});

module.exports = router;