const createApp = require("../app");
const connectDB = require("../config/db");

const app = createApp();

function isStaticAssetRequest(req) {
  const rawUrl = req.url || "";
  const pathname = rawUrl.split("?")[0];

  // Served from /public via express.static
  if (
    pathname.startsWith("/css/") ||
    pathname.startsWith("/js/") ||
    pathname.startsWith("/images/") ||
    pathname.startsWith("/uploads/")
  ) {
    return true;
  }

  // Common asset files
  if (pathname === "/favicon.ico" || pathname === "/robots.txt") return true;

  return false;
}

module.exports = async (req, res) => {
  try {
    if (!isStaticAssetRequest(req)) {
      await connectDB();
    }
    return app(req, res);
  } catch (err) {
    console.error("Request failed:", err);
    if (res.headersSent) return;

    const accepts = req?.headers?.accept || "";
    if (accepts.includes("application/json")) {
      return res.status(503).json({ message: "Service unavailable" });
    }

    return res
      .status(503)
      .send("Service unavailable (database connection failed). Try again later.");
  }
};
