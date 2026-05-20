const mongoose = require("mongoose");

// Cache the connection across hot reloads / serverless invocations.
// eslint-disable-next-line no-underscore-dangle
const cached = global._campusbiteMongoose || (global._campusbiteMongoose = { conn: null, promise: null });

const connectDB = async () => {
  if (cached.conn) return cached.conn;

  const uri = process.env.MONGO_URI?.trim();
  if (!uri) {
    throw new Error("MONGO_URI is not set");
  }

  if (!cached.promise) {
    cached.promise = mongoose
      .connect(uri, {
        // Keep serverless invocations responsive when Atlas is unreachable.
        serverSelectionTimeoutMS: 10000,
        connectTimeoutMS: 10000,
        // Small pool is usually enough for serverless.
        maxPoolSize: 10,
      })
      .then((m) => m.connection)
      .catch((err) => {
        // Allow later invocations to retry after a transient failure.
        cached.promise = null;
        throw err;
      });
  }

  cached.conn = await cached.promise;
  if (cached.conn.readyState === 1) {
    console.log("MongoDB connected");
  }
  return cached.conn;
};

module.exports = connectDB;