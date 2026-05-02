const mongoose = require("mongoose");

const foodItemSchema = new mongoose.Schema({
  name: String,
  price: Number,
  category: String,
  image: String,
});

module.exports = mongoose.model("FoodItem", foodItemSchema);