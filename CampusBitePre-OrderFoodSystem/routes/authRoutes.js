const express = require("express");
const router = express.Router();
const fs = require("fs");
const path = require("path");
const bcrypt = require("bcryptjs");
const User = require("../models/User");
const isLoggedIn = require("../middleware/authMiddleware");
const { uploadProfileImage } = require("../middleware/uploadMiddleware");
const checkRole = require("../middleware/roleMiddleware");
const session = require("express-session");
const {
  parseMediaIdFromPath,
  uploadBufferToGridFS,
  deleteGridFSFileById,
} = require("../config/mediaStore");

const PUBLIC_DIR = path.join(__dirname, "..", "public");

async function safeUnlinkIfExists(absolutePath) {
  try {
    await fs.promises.unlink(absolutePath);
  } catch (err) {
    // ignore missing file and other unlink errors
  }
}

async function deleteOldProfileImage({ userId, oldProfileImagePath, newProfileImagePath }) {
  if (!oldProfileImagePath) return;
  if (oldProfileImagePath === newProfileImagePath) return;

  // GridFS-backed images: /media/<id>
  const oldMediaId = parseMediaIdFromPath(oldProfileImagePath);
  if (oldMediaId) {
    await deleteGridFSFileById(oldMediaId);
    return;
  }

  // Only delete files that live under /images/profile and match our filename convention.
  const oldPath = String(oldProfileImagePath);
  if (!oldPath.startsWith("/images/profile/")) return;

  const oldBaseName = path.posix.basename(oldPath);
  if (!oldBaseName || !String(oldBaseName).startsWith(`${userId}-`)) return;

  const rel = oldPath.replace(/^\/+/, "");
  const absolute = path.resolve(PUBLIC_DIR, rel);

  // Ensure we only delete inside the public dir
  const publicResolved = path.resolve(PUBLIC_DIR) + path.sep;
  if (!absolute.startsWith(publicResolved)) return;

  await safeUnlinkIfExists(absolute);
}

function escapeRegExp(str) {
  return String(str).replace(/[.*+?^${}()|[\]\\]/g, "\\$&");
}

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
      if (existingUser.email === email) return res.redirect(`/auth/register?error=${encodeURIComponent("Email already registered")}`);
      if (existingUser.username === username) return res.redirect(`/auth/register?error=${encodeURIComponent("Username already Exists")}`)
      return res.redirect(`/auth/register?error=${encodeURIComponent("Username/Email already Exists")}`);
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

    return res.redirect(`/auth/login?success=${encodeURIComponent("Account created. Please log in")}`);

  } catch (err) {
    console.log(err);
    return res.send("Registration failed");
  }
});


// Login Page
router.get("/login", (req, res) => {
  res.render("auth/login");
});

// Forgot Password Page
router.get("/forgotPassword", (req, res) => {
  return res.render("auth/forgotPassword");
});

// Forgot Password Submit
router.post("/forgotPassword", async (req, res) => {
  try {
    const username = String(req.body.username || "").trim();
    const email = String(req.body.email || "").trim();
    const password = String(req.body.password || "");
    const confirmPassword = String(req.body.confirmPassword || "");

    if (!username || !email || !password || !confirmPassword) {
      return res.redirect(`/auth/forgotPassword?error=${encodeURIComponent("All fields are required")}`);
    }

    if (password.length < 6) {
      return res.redirect(`/auth/forgotPassword?error=${encodeURIComponent("Password must be at least 6 characters")}`);
    }

    if (password !== confirmPassword) {
      return res.redirect(`/auth/forgotPassword?error=${encodeURIComponent("Passwords do not match")}`);
    }

    const u = escapeRegExp(username);
    const e = escapeRegExp(email);

    const user = await User.findOne({
      username: { $regex: `^${u}$`, $options: "i" },
      email: { $regex: `^${e}$`, $options: "i" },
    });

    if (!user) {
      return res.redirect(`/auth/forgotPassword?error=${encodeURIComponent("Username and email do not match")}`);
    }

    const isSamePassword = await bcrypt.compare(password, user.password);
    if (isSamePassword) {
      return res.redirect(`/auth/forgotPassword?error=${encodeURIComponent("New password must be different from the current password")}`);
    }

    user.password = await bcrypt.hash(password, 10);
    user.resetPasswordTokenHash = "";
    user.resetPasswordExpiresAt = null;
    await user.save();

    return res.redirect(`/auth/login?success=${encodeURIComponent("Password updated. Please log in")}`);
  } catch (err) {
    console.log(err);
    return res.redirect(`/auth/forgotPassword?error=${encodeURIComponent("Failed to reset password")}`);
  }
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
      return res.redirect(`/auth/login?error=${encodeURIComponent("User Not Found")}`);
    }

    const isMatch = await bcrypt.compare(password, user.password);

    if (!isMatch) {
      return res.redirect(`/auth/login?success=${encodeURIComponent("Incorrect Password")}`);
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

    // After a POST, use 303 so the follow-up request is a GET.
    return res.redirect(303, "/dashboard");

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
    return res.redirect(`/auth/login?info=${encodeURIComponent("Logged out")}`);
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
    const username = String(req.body.username || "").trim();
    const email = String(req.body.email || "").trim();
    const password = String(req.body.password || "");
    const confirmPassword = String(req.body.confirmPassword || "");

    if (!req.session.user) {
      return res.redirect("/auth/login");
    }

    if (!username || !email || !password || !confirmPassword) {
      return res.redirect(`/auth/profile?error=${encodeURIComponent("Required fields missing")}`);
    }

    if (password.length < 6) {
      return res.redirect(`/auth/profile?error=${encodeURIComponent("Password must be at least 6 characters")}`);
    }

    if (password !== confirmPassword) {
      return res.redirect(`/auth/profile?error=${encodeURIComponent("Passwords do not match")}`);
    }

    const userId = req.session.user.id;

    const updatedUser = await User.findById(userId);

    if (!updatedUser) {
      return res.redirect(`/auth/profile?error=${encodeURIComponent("User not found")}`);
    }

    const duplicateUser = await User.findOne({
      _id: { $ne: userId },
      $or: [{ username }, { email }],
    });

    if (duplicateUser) {
      if (duplicateUser.email === email) {
        return res.redirect(`/auth/profile?error=${encodeURIComponent("Email already in use")}`);
      }
      if (duplicateUser.username === username) {
        return res.redirect(`/auth/profile?error=${encodeURIComponent("Username already in use")}`);
      }
      return res.redirect(`/auth/profile?error=${encodeURIComponent("Username or email already in use")}`);
    }

    const isSamePassword = await bcrypt.compare(password, updatedUser.password || "");
    if (isSamePassword) {
      return res.redirect(`/auth/profile?error=${encodeURIComponent("New password must be different from the current password")}`);
    }

    updatedUser.username = username;
    updatedUser.email = email;
    updatedUser.password = await bcrypt.hash(password, 10);
    updatedUser.resetPasswordTokenHash = "";
    updatedUser.resetPasswordExpiresAt = null;

    await updatedUser.save();

    // sync session
    req.session.user.username = updatedUser.username;
    req.session.user.email = updatedUser.email;

    // After a POST, use 303 so the follow-up request is a GET.
    return res.redirect(303, `/dashboard?success=${encodeURIComponent("Profile updated")}`);
  } catch (err) {
    console.log(err);
    return res.redirect(`/auth/profile?error=${encodeURIComponent("Profile update failed")}`);
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

    let profileImagePath = "";
    if (req.file.buffer) {
      const id = await uploadBufferToGridFS({
        buffer: req.file.buffer,
        filename: req.file.originalname || "profile-image",
        contentType: req.file.mimetype,
      });
      profileImagePath = `/media/${id.toString()}`;
    } else {
      profileImagePath = `/images/profile/${req.file.filename}`;
    }

    const existingUser = await User.findById(userId).select("profileImage");
    const oldProfileImagePath = existingUser?.profileImage || "";

    const updatedUser = await User.findByIdAndUpdate(
      userId,
      { profileImage: profileImagePath },
      { new: true }
    ).select("profileImage");

    if (!updatedUser) {
      // DB update failed; remove newly uploaded file to avoid orphaned files.
      const newMediaId = parseMediaIdFromPath(profileImagePath);
      await deleteGridFSFileById(newMediaId);

      if (req.file.path) {
        const uploadedAbsolute =
          req.file.path || path.resolve(PUBLIC_DIR, "images", "profile", req.file.filename);
        await safeUnlinkIfExists(uploadedAbsolute);
      }
      return res.status(404).send("User not found");
    }

    req.session.user.profileImage = updatedUser.profileImage || "";

    await deleteOldProfileImage({
      userId,
      oldProfileImagePath,
      newProfileImagePath: profileImagePath,
    });

    return res.redirect(303, `/auth/profile?success=${encodeURIComponent("Profile picture updated")}`);
  } catch (err) {
    console.log(err);

    // If something fails after multer wrote the file, try to clean it up.
    if (req.file) {
      if (req.file.path) {
        const uploadedAbsolute =
          req.file.path || path.resolve(PUBLIC_DIR, "images", "profile", req.file.filename);
        await safeUnlinkIfExists(uploadedAbsolute);
      }
    }

    return res.status(500).send("Profile image update failed");
  }
});

router.get("/manageUser", isLoggedIn, checkRole("admin"), async(req, res) => {
  if(!req.session.user){
    return res.redirect("/auth/login");
  }

  try {
    const users = await User.find({})
      .select("username email role merchantType createdAt")
      .sort({ createdAt: -1 })
      .lean();

    return res.render("admin/manageUser", {
      admin: req.session.user,
      users,
    });
  } catch (err) {
    console.log(err);
    return res.send("Error loading users");
  }
});

// Admin: edit user page
router.get("/users/:userId/edit", isLoggedIn, checkRole("admin"), async (req, res) => {
  try {
    const { userId } = req.params;
    const editUser = await User.findById(userId)
      .select("username email role merchantType createdAt")
      .lean();

    if (!editUser) {
      return res.redirect(`/auth/manageUser?error=${encodeURIComponent("User not found")}`);
    }

    return res.render("admin/editUser", {
      admin: req.session.user,
      editUser,
    });
  } catch (err) {
    console.log(err);
    return res.redirect(`/auth/manageUser?error=${encodeURIComponent("Failed to load user")}`);
  }
});

// Admin: edit user submit
router.post("/users/:userId/edit", isLoggedIn, checkRole("admin"), async (req, res) => {
  try {
    const { userId } = req.params;
    const { username, email, role, merchantType, password } = req.body;

    if (!username || !email || !role) {
      return res.redirect(
        `/auth/users/${encodeURIComponent(userId)}/edit?error=${encodeURIComponent("Required fields missing")}`
      );
    }

    const allowedRoles = new Set(["student", "merchant", "admin"]);
    if (!allowedRoles.has(role)) {
      return res.redirect(
        `/auth/users/${encodeURIComponent(userId)}/edit?error=${encodeURIComponent("Invalid role")}`
      );
    }

    // Prevent locking yourself out
    if (String(req.session.user.id) === String(userId) && role !== "admin") {
      return res.redirect(
        `/auth/users/${encodeURIComponent(userId)}/edit?error=${encodeURIComponent("You cannot remove your own admin role")}`
      );
    }

    const user = await User.findById(userId);
    if (!user) {
      return res.redirect(`/auth/manageUser?error=${encodeURIComponent("User not found")}`);
    }

    user.username = String(username).trim();
    user.email = String(email).trim();
    user.role = role;
    user.merchantType = role === "merchant" ? String(merchantType || "").trim() : "";

    const newPassword = String(password || "");
    if (newPassword.trim().length > 0) {
      user.password = await bcrypt.hash(newPassword, 10);
    }

    await user.save();

    return res.redirect(`/auth/manageUser?success=${encodeURIComponent("User updated")}`);
  } catch (err) {
    console.log(err);

    if (err && (err.code === 11000 || err.code === 11001)) {
      return res.redirect(
        `/auth/users/${encodeURIComponent(req.params.userId)}/edit?error=${encodeURIComponent("Email already exists")}`
      );
    }

    return res.redirect(
      `/auth/users/${encodeURIComponent(req.params.userId)}/edit?error=${encodeURIComponent("Update failed")}`
    );
  }
});

module.exports = router;