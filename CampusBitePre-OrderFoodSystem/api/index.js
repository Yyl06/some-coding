const createApp = require("../app");
const connectDB = require("../config/db");

const app = createApp();

module.exports = async (req, res) => {
  await connectDB();
  return app(req, res);
};
