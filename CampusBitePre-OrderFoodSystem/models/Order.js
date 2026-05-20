const mongoose = require("mongoose");

const orderSchema = new mongoose.Schema({
  student: {
    type: mongoose.Schema.Types.ObjectId,
    ref: "User",
  },

  studentName: {
    type: String,
    default: "",
  },

  merchant: {
    type: mongoose.Schema.Types.ObjectId,
    ref: "User",
  },

  items: [
    {
      food: {
        type: mongoose.Schema.Types.ObjectId,
        ref: "FoodItem",
      },
      foodName: {
        type: String,
        default: "",
      },
      unitPrice: {
        type: mongoose.Schema.Types.Decimal128,
      },
      quantity: {
        type: Number,
        default: 1,
      },
    },
  ],

  totalPrice: {
    type: mongoose.Schema.Types.Decimal128,
    required: true,
  },

  fulfillmentType: {
    type: String,
    default: "pickup",
  },

  paymentMethod: {
    type: String,
    default: "pay_on_pickup",
  },

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