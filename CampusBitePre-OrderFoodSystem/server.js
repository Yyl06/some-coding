const express = require("express");

const app = express();
const PORT = 3000;

app.use(express.json());

app.get("/", (req, res) => {
  res.send("CampusBite backend is running 🍔💀");
});

app.listen(PORT, async () => {
  console.log(`Server running on http://localhost:${PORT}`);

  const open = (await import("open")).default;
  open(`http://localhost:${PORT}`);
});