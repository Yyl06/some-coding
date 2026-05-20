require("dotenv").config();

const createApp = require("./app");
const connectDB = require("./config/db");

const app = createApp();
const PORT = process.env.PORT || 3000;

async function start() {
  await connectDB();
  app.listen(PORT, () => {
    const url = `http://localhost:${PORT}`;
    console.log(`Server running on ${url}`);
  });
}

if (require.main === module) {
  start().catch((err) => {
    console.error("Failed to start server:", err);
    process.exit(1);
  });
}

module.exports = app;