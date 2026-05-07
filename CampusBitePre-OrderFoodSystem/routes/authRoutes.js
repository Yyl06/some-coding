const express = require("express");
const router = express.Router();
const bcrypt = require("bcryptjs");
const User = require("../models/User");

// Register Page
router.get("/register", (req, res) => {
  res.render("auth/register");
});


// Register
router.post("/register", async (req, res) => {
  try {
    const { username, email, password, role } = req.body;

    if (!username || !email || !password) {
      return res.status(400).send("Required fields missing");
    }

    // Prevent privilege escalation (e.g. sending role=admin)
    const safeRole = role === "merchant" ? "merchant" : "student";

    const existingUser = await User.findOne({
      $or: [{ email }, { username }],
    });

    if (existingUser) {
      if (existingUser.email === email) return res.send("Email already registered");
      if (existingUser.username === username) return res.send("Username already taken");
      return res.send("User already exists");
    }

    const hashedPassword = await bcrypt.hash(password, 10);

    const newUser = new User({
      username,
      email,
      password: hashedPassword,
      role: safeRole,
    });

    await newUser.save();

    return res.redirect("/auth/login");

  } catch (err) {
    console.log(err);
    return res.send("Registration failed");
  }
});


// Login Page
router.get("/login", (req, res) => {
  res.render("auth/login");
});


// Login
router.post("/login", async (req, res) => {
  try {
    const { identifier, email, password } = req.body;

    const loginId = (identifier || email || "").trim();

    if (!loginId || !password) {
      return res.status(400).send("Required fields missing");
    }

    const user = await User.findOne({
      $or: [{ email: loginId }, { username: loginId }],
    });

    if (!user) {
      return res.send("User not found");
    }

    const isMatch = await bcrypt.compare(password, user.password);

    if (!isMatch) {
      return res.send("Invalid password");
    }

    await new Promise((resolve, reject) => {
      req.session.regenerate((err) => (err ? reject(err) : resolve()));
    });

    req.session.user = {
      id: user._id.toString(),
      username: user.username,
      email: user.email,
      role: user.role,
    };

    await new Promise((resolve, reject) => {
      req.session.save((err) => (err ? reject(err) : resolve()));
    });

    return res.redirect("/dashboard");

  } catch (err) {
    console.log(err);
    return res.send("Login failed");
  }
});


// Logout
router.get("/logout", (req, res) => {
  req.session.destroy((err) => {
    if (err) {
      console.log(err);
      return res.send("Logout error");
    }
    return res.redirect("/auth/login");
  });
});

//Get profile
router.get("/profile", (req, res) => {
  if (!req.session.user) {
    return res.redirect("/auth/login");
  }

  res.render("auth/profile", {
    user: req.session.user
  });
});

//Update Profile
router.post("/profile", async (req, res) => {
  try {
    const { username, email, phoneNumber } = req.body;

    if (!req.session.user) {
      return res.redirect("/auth/login");
    }

    if (!username || !email) {
      return res.send("Required fields missing");
    }

    const userId = req.session.user.id;

    const updatedUser = await User.findByIdAndUpdate(
      userId,
      { username, email},
      { new: true }
    );

    if (!updatedUser) {
      return res.send("User not found");
    }

    // sync session
    req.session.user.username = updatedUser.username;
    req.session.user.email = updatedUser.email;

    return res.redirect("/dashboard");
  } catch (err) {
    console.log(err);
    return res.send("Profile update failed");
  }
});

module.exports = router;