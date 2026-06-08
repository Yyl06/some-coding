// getMerchants.js
const mongoose = require("mongoose");
const User = require("./models/User");

require("dotenv").config();

async function run() {
  try {
    await mongoose.connect(process.env.MDB_CONNECTION_STRING);

    const merchants = await User.find(
      {
        username: {
          $in: [
            "merchant06",
            "merchant07",
            "merchant08",
            "merchant09",
            "merchant10",
            "merchant11",
            "merchant12",
            "merchant13",
            "merchant14",
            "merchant15",
          ],
        },
      },
      "_id username"
    );

    console.table(
      merchants.map((m) => ({
        username: m.username,
        id: m._id.toString(),
      }))
    );
  } catch (err) {
    console.error(err);
  } finally {
    await mongoose.disconnect();
  }
}

run();