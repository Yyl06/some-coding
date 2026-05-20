const mongoose = require("mongoose");

const foodItemSchema = new mongoose.Schema({
  name: {
    type: String,
    required: true,
  },

  price: {
    type: mongoose.Schema.Types.Decimal128,
    required: true,
    validate: {
      validator: (value) => {
        if (value == null) return false;
        const n = Number(typeof value?.toString === "function" ? value.toString() : value);
        return Number.isFinite(n) && n > 0;
      },
      message: "Price must be greater than 0",
    },
  },

  category: {
    type: String,
    required: true,
    trim: true,
    maxlength: 40,
    match: [/^[A-Za-z][A-Za-z\s]*$/, "Category must contain only letters and spaces"],
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