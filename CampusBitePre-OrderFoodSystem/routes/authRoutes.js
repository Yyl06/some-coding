const express = require("express");
const router = express.Router();
const bcrypt = require("bcryptjs");
const User = require("../models/User");
const isLoggedIn = require("../middleware/authMiddleware");
const { uploadProfileImage } = require("../middleware/uploadMiddleware");

// Register Page
router.get("/register", (req, res) => {
  res.render("auth/register");
});


// Register
router.post("/register", async (req, res) => {
  try {
    const { username, email, password, role, merchantType } = req.body;

    if (!username || !email || !password) {
      return res.status(400).send("Required fields missing");
    }

    // Prevent privilege escalation (e.g. sending role=admin)
    const safeRole = role === "merchant" ? "merchant" : "student";
    const safeMerchantType = safeRole === "merchant" ? (merchantType || "") : "";

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
      merchantType: safeMerchantType,
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
      profileImage: user.profileImage || "",
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
router.get("/profile", async (req, res) => {
  if (!req.session.user) {
    return res.redirect("/auth/login");
  }

  try {
    const dbUser = await User.findById(req.session.user.id).select(
      "username email role profileImage"
    );

    if (dbUser) {
      req.session.user.username = dbUser.username;
      req.session.user.email = dbUser.email;
      req.session.user.role = dbUser.role;
      req.session.user.profileImage = dbUser.profileImage || "";
    }
  } catch (err) {
    console.log(err);
  }

  return res.render("auth/profile", {
    user: req.session.user,
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

// Upload / Update Profile Image
router.post("/profile/image", isLoggedIn, (req, res, next) => {
  uploadProfileImage.single("profileImage")(req, res, (err) => {
    if (err) {
      console.log(err);
      return res.status(400).send(err.message || "Image upload failed");
    }
    return next();
  });
}, async (req, res) => {
  try {
    if (!req.file) {
      return res.status(400).send("No image uploaded");
    }

    const userId = req.session.user.id;
    const profileImagePath = `/images/profile/${req.file.filename}`;

    const updatedUser = await User.findByIdAndUpdate(
      userId,
      { profileImage: profileImagePath },
      { new: true }
    ).select("profileImage");

    if (!updatedUser) {
      return res.status(404).send("User not found");
    }

    req.session.user.profileImage = updatedUser.profileImage || "";

    return res.redirect("/auth/profile");
  } catch (err) {
    console.log(err);
    return res.status(500).send("Profile image update failed");
  }
});

module.exports = router;