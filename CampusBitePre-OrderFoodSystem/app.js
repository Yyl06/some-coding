require("dotenv").config();

const express = require("express");
const path = require("path");
const session = require("express-session");

const connectDB = require("./config/db");

const homeRoutes = require("./routes/homeRoutes");
const authRoutes = require("./routes/authRoutes");
const foodRoutes = require("./routes/foodRoutes");
const menuRoute = require("./routes/menuRoute");
const shopRoutes = require("./routes/shopRoutes");
const orderRoutes = require("./routes/orderRoutes");
const mediaRoutes = require("./routes/mediaRoutes");

function createApp() {
  const app = express();

  // Needed for secure cookies behind Vercel/other proxies
  if (process.env.NODE_ENV === "production" || process.env.VERCEL) {
    app.set("trust proxy", 1);
  }

  app.use(express.json());
  app.use(express.urlencoded({ extended: true }));

  // Ensure browser follows POST redirects with a GET.
  // This prevents method-preserving redirects (307/308) from breaking form flows.
  app.use((req, res, next) => {
    const originalRedirect = res.redirect.bind(res);
    res.redirect = (statusOrUrl, url) => {
      if (req.method === "POST" && typeof statusOrUrl === "string") {
        return originalRedirect(303, statusOrUrl);
      }
      return originalRedirect(statusOrUrl, url);
    };
    next();
  });

  app.set("view engine", "ejs");
  app.set("views", path.join(__dirname, "views"));
  app.use(express.static(path.join(__dirname, "public")));

  // Session store: MemoryStore is not suitable for serverless.
  // If connect-mongo is available, use MongoDB-backed sessions.
  let store;
  try {
    // eslint-disable-next-line global-require
    const MongoStore = require("connect-mongo");
    if (process.env.MONGO_URI) {
      store = MongoStore.create({
        mongoUrl: process.env.MONGO_URI,
        collectionName: "sessions",
        ttl: 60 * 60 * 24 * 14, // 14 days
      });
    }
  } catch (err) {
    // connect-mongo not installed; fall back to MemoryStore (ok for local dev).
  }

  app.use(
    session({
      name: "campusbite.sid",
      secret: process.env.SESSION_SECRET || "dev_only_change_me",
      resave: false,
      saveUninitialized: false,
      proxy: process.env.NODE_ENV === "production" || Boolean(process.env.VERCEL),
      store,
      cookie: {
        httpOnly: true,
        sameSite: "lax",
        secure: process.env.NODE_ENV === "production" || Boolean(process.env.VERCEL),
      },
    })
  );

  app.use("/media", mediaRoutes);
  app.use("/", homeRoutes);
  app.use("/auth", authRoutes);
  app.use("/foods", foodRoutes);
  app.use("/menu", menuRoute);
  app.use("/shops", shopRoutes);
  app.use("/orders", orderRoutes);

  // Warm DB connection for environments that keep the process warm
  // (serverless may call this per request instead; that's fine with caching).
  connectDB().catch(() => {
    // Defer errors to request time or server start handlers.
  });

  return app;
}

module.exports = createApp;
