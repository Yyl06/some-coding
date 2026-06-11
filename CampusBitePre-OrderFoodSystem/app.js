require("dotenv").config();

const express = require("express");
const path = require("path");
const session = require("express-session");

const homeRoutes = require("./routes/homeRoutes");
const authRoutes = require("./routes/authRoutes");
const foodRoutes = require("./routes/foodRoutes");
const menuRoute = require("./routes/menuRoute");
const shopRoutes = require("./routes/shopRoutes");
const orderRoutes = require("./routes/orderRoutes");
const mediaRoutes = require("./routes/mediaRoutes");

const faviconPath = path.join(__dirname, "public", "images", "foods", "campusbite_logo.png");

function createApp() {
  const app = express();

  // Needed for secure cookies behind Vercel/other proxies
  if (process.env.NODE_ENV === "production" || process.env.VERCEL) {
    // Vercel can sit behind multiple proxies; trust them so req.secure works.
    app.set("trust proxy", true);
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
  app.get(["/favicon.ico", "/favicon.png", "/apple-touch-icon.png", "/icon.png"], (req, res) => {
    res.type("png");
    res.set("Cache-Control", "public, max-age=86400");
    return res.sendFile(faviconPath);
  });
  app.use(express.static(path.join(__dirname, "public")));

  // Session store: MemoryStore is not suitable for serverless.
  // If connect-mongo is available, use MongoDB-backed sessions.
  let store;
  const mongoUrl = process.env.MONGO_URI?.trim();
  if (mongoUrl) {
    try {
      // connect-mongo v6 CommonJS export shape: { default: MongoStore, MongoStore, ... }
      // eslint-disable-next-line global-require
      const connectMongo = require("connect-mongo");
      const MongoStore = connectMongo?.default || connectMongo?.MongoStore || connectMongo;

      if (typeof MongoStore?.create !== "function") {
        throw new TypeError("connect-mongo does not expose MongoStore.create");
      }

      store = MongoStore.create({
        mongoUrl,
        collectionName: "sessions",
        ttl: 60 * 60 * 24 * 14, // 14 days
      });
    } catch (err) {
      console.error("Failed to configure Mongo session store:", err);
    }
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
        // Persist across navigations; helps avoid "random" logouts.
        maxAge: 1000 * 60 * 60 * 24 * 14, // 14 days
        // Some browsers are picky with cross-subdomain POSTs on preview URLs.
        sameSite:
          process.env.NODE_ENV === "production" || Boolean(process.env.VERCEL)
            ? "none"
            : "lax",
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

  return app;
}

module.exports = createApp;
