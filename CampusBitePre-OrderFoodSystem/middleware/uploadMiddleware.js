const fs = require("fs");
const path = require("path");
const multer = require("multer");

function ensureDirSync(dirPath) {
  try {
    fs.mkdirSync(dirPath, { recursive: true });
  } catch (err) {
    // ignore EEXIST and similar races
  }
}

const mimeToExt = {
  "image/jpeg": ".jpg",
  "image/jpg": ".jpg",
  "image/pjpeg": ".jpg",
  "image/png": ".png",
  "image/webp": ".webp",
  "image/gif": ".gif",
};

function makeImageUploader(relativeUploadsDir) {
  const runningOnVercel =
    process.env.NODE_ENV === "production" || Boolean(process.env.VERCEL);

  let storage;

  if (runningOnVercel) {
    // Vercel serverless file system is not writable in the deployed bundle.
    // Use memory storage and persist the file elsewhere (e.g., GridFS).
    storage = multer.memoryStorage();
  } else {
    const absoluteUploadsDir = path.join(
      __dirname,
      "..",
      "public",
      ...relativeUploadsDir
    );
    ensureDirSync(absoluteUploadsDir);

    storage = multer.diskStorage({
      destination: (req, file, cb) => {
        cb(null, absoluteUploadsDir);
      },
      filename: (req, file, cb) => {
        const originalExt = path.extname(file.originalname || "").toLowerCase();
        const extFromMime = mimeToExt[file.mimetype];
        const ext =
          file.mimetype === "image/jpeg" && originalExt === ".jpeg"
            ? ".jpeg"
            : extFromMime || originalExt || "";
        const userId = req.session?.user?.id || "anon";
        cb(null, `${userId}-${Date.now()}${ext || ""}`);
      },
    });
  }

  const allowedMimeTypes = new Set(Object.keys(mimeToExt));

  function imageFileFilter(req, file, cb) {
    if (allowedMimeTypes.has(file.mimetype)) return cb(null, true);
    return cb(
      new Error("Only image files are allowed (jpg, jpeg, png, webp, gif).")
    );
  }

  return multer({
    storage,
    fileFilter: imageFileFilter,
    limits: {
      fileSize: 2 * 1024 * 1024, // 2MB
    },
  });
}

const uploadProfileImage = makeImageUploader(["images", "profile"]);
const uploadFoodImage = makeImageUploader(["images", "foods"]);

module.exports = {
  uploadProfileImage,
  uploadFoodImage,
};
