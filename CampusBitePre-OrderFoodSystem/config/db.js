const mongoose = require("mongoose");

// Cache the connection across hot reloads / serverless invocations.
// eslint-disable-next-line no-underscore-dangle
const cached = global._campusbiteMongoose || (global._campusbiteMongoose = { conn: null, promise: null });

const connectDB = async () => {
  if (cached.conn) return cached.conn;

  const uri = process.env.MONGO_URI;
  if (!uri) {
    throw new Error("MONGO_URI is not set");
  }

  if (!cached.promise) {
    cached.promise = mongoose.connect(uri).then((m) => m.connection);
  }

  cached.conn = await cached.promise;
  if (cached.conn.readyState === 1) {
    console.log("MongoDB connected");
  }
  return cached.conn;
};

module.exports = connectDB;