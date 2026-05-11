require("dotenv").config();

const fs = require("fs");
const path = require("path");
const mongoose = require("mongoose");

const connectDB = require("../config/db");
const User = require("../models/User");
const FoodItem = require("../models/FoodItem");

function ensureDirSync(dirPath) {
  fs.mkdirSync(dirPath, { recursive: true });
}

function toFsPathFromPublicUrl(projectRoot, publicUrl) {
  const relative = String(publicUrl || "").replace(/^\//, "");
  return path.join(projectRoot, "public", relative);
}

async function migrateField({
  model,
  field,
  oldPrefix,
  newPrefix,
  oldDirRelative,
  newDirRelative,
  projectRoot,
}) {
  const oldDir = path.join(projectRoot, "public", oldDirRelative);
  const newDir = path.join(projectRoot, "public", newDirRelative);
  ensureDirSync(newDir);

  const docs = await model.find({
    [field]: { $regex: `^${oldPrefix.replace(/\//g, "\\/")}` },
  });

  let updated = 0;
  let moved = 0;
  let missingFiles = 0;
  let moveSkippedExists = 0;

  for (const doc of docs) {
    const current = doc[field];
    if (typeof current !== "string" || !current.startsWith(oldPrefix)) continue;

    const filename = path.posix.basename(current);
    const nextValue = `${newPrefix}${filename}`;

    // Update DB field
    doc[field] = nextValue;
    await doc.save();
    updated += 1;

    // Move file if present
    const oldFsPath = toFsPathFromPublicUrl(projectRoot, current);
    const newFsPath = toFsPathFromPublicUrl(projectRoot, nextValue);

    try {
      if (!fs.existsSync(oldFsPath)) {
        missingFiles += 1;
        continue;
      }

      if (fs.existsSync(newFsPath)) {
        moveSkippedExists += 1;
        continue;
      }

      ensureDirSync(path.dirname(newFsPath));
      fs.renameSync(oldFsPath, newFsPath);
      moved += 1;
    } catch (err) {
      console.log(`Failed to move file for ${model.modelName} ${doc._id}:`, err);
    }
  }

  return { updated, moved, missingFiles, moveSkippedExists, oldDir, newDir };
}

async function main() {
  const projectRoot = path.join(__dirname, "..");

  await connectDB();

  const results = [];

  results.push(
    await migrateField({
      model: User,
      field: "profileImage",
      oldPrefix: "/uploads/profile/",
      newPrefix: "/images/profile/",
      oldDirRelative: path.join("uploads", "profile"),
      newDirRelative: path.join("images", "profile"),
      projectRoot,
    })
  );

  results.push(
    await migrateField({
      model: FoodItem,
      field: "image",
      oldPrefix: "/uploads/foods/",
      newPrefix: "/images/foods/",
      oldDirRelative: path.join("uploads", "foods"),
      newDirRelative: path.join("images", "foods"),
      projectRoot,
    })
  );

  console.log("\nMigration complete:");
  console.table(
    results.map((r) => ({
      updated: r.updated,
      moved: r.moved,
      missingFiles: r.missingFiles,
      moveSkippedExists: r.moveSkippedExists,
      from: r.oldDir,
      to: r.newDir,
    }))
  );
}

main()
  .catch((err) => {
    console.error(err);
    process.exitCode = 1;
  })
  .finally(async () => {
    try {
      await mongoose.connection.close();
    } catch {
      // ignore
    }
  });
