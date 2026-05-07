require("dotenv").config();

const mongoose = require("mongoose");
const bcrypt = require("bcryptjs");

const User = require("../models/User");

mongoose.connect(process.env.MONGO_URI);

async function createAdmin() {
  try {
    // Check if admin already exists
    const existingAdmin = await User.findOne({
      email: process.env.ADMIN_EMAIL,
    });

    if (existingAdmin) {
      console.log("Admin already exists");
      process.exit();
    }

    // Hash password
    const hashedPassword = await bcrypt.hash(
        process.env.ADMIN_PASSWORD,
        10
    );

    // Create admin
    const admin = new User({
      username: "Admin",
      email: process.env.ADMIN_EMAIL,
      password: hashedPassword,
      role: "admin",
    });

    await admin.save();

    console.log("Admin account created successfully");

    process.exit();
  } catch (err) {
    console.log(err);
    process.exit();
  }
}

createAdmin();