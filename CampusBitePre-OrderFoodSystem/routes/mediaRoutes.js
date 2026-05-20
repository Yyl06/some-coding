const express = require("express");
const mongoose = require("mongoose");
const { GridFSBucket, ObjectId } = require("mongodb");

const connectDB = require("../config/db");

const router = express.Router();

router.get("/:id", async (req, res) => {
  try {
    await connectDB();

    const db = mongoose.connection?.db;
    if (!db) {
      return res.status(503).send("Database not ready");
    }

    let fileId;
    try {
      fileId = new ObjectId(String(req.params.id));
    } catch {
      return res.status(400).send("Invalid media id");
    }

    const bucket = new GridFSBucket(db, { bucketName: "media" });

    const files = await bucket.find({ _id: fileId }).limit(1).toArray();
    const file = files[0];
    if (!file) return res.sendStatus(404);

    if (file.contentType) {
      res.setHeader("Content-Type", file.contentType);
    }

    // Cache aggressively; URLs are content-addressed by id.
    res.setHeader("Cache-Control", "public, max-age=31536000, immutable");

    const stream = bucket.openDownloadStream(fileId);
    stream.on("error", () => {
      if (!res.headersSent) res.sendStatus(404);
    });

    return stream.pipe(res);
  } catch (err) {
    console.log(err);
    return res.status(500).send("Failed to load media");
  }
});

module.exports = router;
