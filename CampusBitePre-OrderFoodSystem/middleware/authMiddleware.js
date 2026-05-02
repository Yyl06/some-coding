function isLoggedIn(req, res, next) {
  if (req.session && req.session.user) {
    return next();
  } else {
    return res.send("Access denied. Please login first.");
    return res.redirect("/auth/login");
  }
}

module.exports = isLoggedIn;