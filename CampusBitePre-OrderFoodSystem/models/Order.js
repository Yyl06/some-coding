const mongoose = require("mongoose");

const orderSchema = new mongoose.Schema({
  studentName: String,

  items: [
    {
      foodName: String,
      quantity: Number,
    },
  ],

  totalPrice: Number,

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