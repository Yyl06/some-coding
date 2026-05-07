function isLoggedIn(req, res, next) {
  if (req.session && req.session.user) return next();

  const accepts = req.accepts(["html", "json"]);
  if (accepts === "json") {
    return res.status(401).json({ message: "Unauthorized" });
  }

  return res.redirect("/auth/login");
}

module.exports = isLoggedIn;