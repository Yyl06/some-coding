const { Decimal128 } = require("mongodb");
const mongoose = require("mongoose");

const foodItemSchema = new mongoose.Schema({
  name: {
    type: String,
    required: true,
  },

  price: {
    type: Decimal128,
    required: true,
  },

  category: {
    type: String,
    required: true,
  },

  description: {
    type: String,
  },

  availability: {
    type: Boolean,
    default: true,
  },

  image: {
    type: String,
    default: "",
  },

  merchant: {
    type: mongoose.Schema.Types.ObjectId,
    ref: "User",
    required: true,
  },

});

module.exports = mongoose.model("FoodItem", foodItemSchema);