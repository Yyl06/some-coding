const fs = require("fs");
const path = require("path");
const bcrypt = require("bcryptjs");

async function main() {
  const count = Math.max(1, Math.min(200, parseInt(process.argv[2] || "12", 10) || 12));
  const plainPassword = String(process.argv[3] || "TestPass123!");
  const prefix = String(process.argv[4] || "merchant");
  const domain = String(process.argv[5] || "campusbite.test");
  const startIndex = Math.max(1, parseInt(process.argv[6] || "1", 10) || 1);

  const types = ["Hawker Centre", "Cafe", "Desserts", "Beverages", "Other"];
  const createdAt = new Date().toISOString();

  const merchants = [];

  const maxIndex = startIndex + count - 1;
  const width = Math.max(2, String(maxIndex).length);

  for (let offset = 0; offset < count; offset += 1) {
    const idx = startIndex + offset;
    const n = String(idx).padStart(width, "0");

    const username = `${prefix}${n}`;
    const email = `${prefix}${n}@${domain}`;
    const merchantType = types[offset % types.length];

    const passwordHash = await bcrypt.hash(plainPassword, 10);

    merchants.push({
      username,
      email,
      password: passwordHash,
      role: "merchant",
      merchantType,
      profileImage: "",
      createdAt: { $date: createdAt },
    });
  }

  const outPath = path.join(__dirname, "dummyMerchants.json");
  fs.writeFileSync(outPath, JSON.stringify(merchants, null, 2) + "\n", "utf8");

  console.log(`Wrote ${merchants.length} merchants to ${outPath}`);
  console.log(`Login password for all: ${plainPassword}`);
}

main().catch((err) => {
  console.error(err);
  process.exit(1);
});
