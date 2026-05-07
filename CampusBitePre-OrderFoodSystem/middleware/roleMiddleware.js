function checkRole(...allowedRoles) {
  return (req, res, next) => {
    if (!req.session.user) {
      return res.send("Please login first");
    }

    const userRole = req.session.user.role;

    if (!allowedRoles.includes(userRole)) {
      return res.send("Access denied");
    }

    next();
  };
}

module.exports = checkRole;