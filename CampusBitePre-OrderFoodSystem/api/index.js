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
  if (!isStaticAssetRequest(req)) {
    await connectDB();
  }
  return app(req, res);
};
