const session = require("express-session");
require("dotenv").config();
const express = require("express");
const path = require("path");
const connectDB = require("./config/db");

const app = express();
const PORT = process.env.PORT || 3000;

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.set("view engine", "ejs");
app.set("views", path.join(__dirname, "views"));

app.use(express.static(path.join(__dirname, "public")));

app.use(
  session({
    name: "campusbite.sid",
    secret: process.env.SESSION_SECRET || "dev_only_change_me",
    resave: false,
    saveUninitialized: false,
    cookie: {
      httpOnly: true,
      sameSite: "lax",
      secure: process.env.NODE_ENV === "production",
    },
  })
);

const homeRoutes = require("./routes/homeRoutes");
app.use("/", homeRoutes);
const authRoutes = require("./routes/authRoutes");
app.use("/auth", authRoutes);
const foodRoutes = require("./routes/foodRoutes");
app.use("/foods", foodRoutes);
const menuRoute = require("./routes/menuRoute");
app.use("/menu", menuRoute);
const shopRoutes = require("./routes/shopRoutes");
app.use("/shops", shopRoutes);

// connect DB then start server
connectDB().then(() => {
  app.listen(PORT, () => {
    const url = `http://localhost:${PORT}`;
    console.log(`Server running on ${url}`);
  });
});