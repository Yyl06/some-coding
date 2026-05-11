const { Decimal128 } = require("mongodb");
const mongoose = require("mongoose");

const orderSchema = new mongoose.Schema({
  studentName: String,

  items: [
    {
      foodName: String,
      quantity: Number,
    },
  ],

  totalPrice: Decimal128,

  status: {
    type: String,
    default: "Pending",
  },

  createdAt: {
    type: Date,
    default: Date.now,
  },
});

module.exports = mongoose.model("Order", orderSchema);