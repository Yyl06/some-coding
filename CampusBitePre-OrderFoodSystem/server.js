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
    secret: "campusbite_secret",
    resave: false,
    saveUninitialized: false,
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

app.get("/dashboard", (req, res) => {
  if (!req.session.user) return res.redirect("/auth/login");

  res.render("dashboard", { user: req.session.user });
});

// connect DBs
connectDB();

app.listen(PORT, () => {
  console.log(`Server running on http://localhost:${PORT}`);
});