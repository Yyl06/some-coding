const mongoose = require("mongoose");
const { GridFSBucket, ObjectId } = require("mongodb");

const connectDB = require("./db");

async function getBucket() {
  await connectDB();
  const db = mongoose.connection?.db;
  if (!db) {
    throw new Error("Database not ready");
  }
  return new GridFSBucket(db, { bucketName: "media" });
}

function parseMediaIdFromPath(mediaPath) {
  if (typeof mediaPath !== "string") return null;
  const match = mediaPath.match(/^\/media\/([a-fA-F0-9]{24})$/);
  return match ? match[1] : null;
}

async function uploadBufferToGridFS({ buffer, filename, contentType }) {
  if (!buffer || !Buffer.isBuffer(buffer)) {
    throw new Error("Missing file buffer");
  }

  const bucket = await getBucket();

  return new Promise((resolve, reject) => {
    const safeName = String(filename || "upload");
    const uploadStream = bucket.openUploadStream(safeName, {
      contentType: contentType || "application/octet-stream",
    });

    uploadStream.on("finish", () => resolve(uploadStream.id));
    uploadStream.on("error", reject);
    uploadStream.end(buffer);
  });
}

async function deleteGridFSFileById(id) {
  if (!id) return;

  const bucket = await getBucket();

  let fileId;
  try {
    fileId = typeof id === "string" ? new ObjectId(id) : id;
  } catch {
    return;
  }

  try {
    await bucket.delete(fileId);
  } catch {
    // ignore missing file and delete failures
  }
}

module.exports = {
  parseMediaIdFromPath,
  uploadBufferToGridFS,
  deleteGridFSFileById,
};
