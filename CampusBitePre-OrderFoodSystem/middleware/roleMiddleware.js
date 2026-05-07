function checkRole(...allowedRoles) {
  return (req, res, next) => {
    if (!req.session.user) {
      const accepts = req.accepts(["html", "json"]);
      if (accepts === "json") {
        return res.status(401).json({ message: "Unauthorized" });
      }

      return res.redirect("/auth/login");
    }

    const userRole = req.session.user.role;

    if (!allowedRoles.includes(userRole)) {
      const accepts = req.accepts(["html", "json"]);
      if (accepts === "json") {
        return res.status(403).json({ message: "Forbidden" });
      }

      return res.status(403).send("Access denied");
    }

    next();
  };
}

module.exports = checkRole;