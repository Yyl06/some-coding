<?php
session_start();

if (!isset($_SESSION['user_id']) || !in_array($_SESSION['role_id'], [1, 2])) {
    echo "<script>alert('Access Denied. Admins only.'); window.location.href = '../Login/login.php';</script>";
    exit;
}

$con = mysqli_connect('localhost', 'root', '', 'fbs');
if (mysqli_connect_errno()) {
    die("Connection failed: " . mysqli_connect_error());
}

if (isset($_GET['delete'])) {
    $id = $_GET['delete'];
    $stmt = $con->prepare("DELETE FROM users WHERE user_id = ?");
    $stmt->bind_param("i", $id);
    $stmt->execute();
    header("Location: modify.php?msg=deleted");
    exit;
}

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $action = $_POST['action'];
    $username = $_POST['username'];
    $role_id = $_POST['role_id'];

    if ($action === 'add') {
        $password = password_hash($_POST['password'], PASSWORD_DEFAULT);

        $stmt = $con->prepare("INSERT INTO users (username, password, role_id) VALUES (?, ?, ?)");
        $stmt->bind_param("ssi", $username, $password, $role_id);
        $stmt->execute();

        $new_user_id = $stmt->insert_id;

        $stmt->close();
        header("Location: modify.php?msg=added");
        exit;
    }

    if ($action === 'edit') {
        $user_id = $_POST['user_id'];

        $stmt = $con->prepare("UPDATE users SET username = ?, role_id = ? WHERE user_id = ?");
        $stmt->bind_param("sii", $username, $role_id, $user_id);
        $stmt->execute();
        $stmt->close();

        header("Location: modify.php?msg=updated");
        exit;
    }
}

$roles = mysqli_query($con, "SELECT * FROM role");
$roleOptions = [];
while ($r = mysqli_fetch_assoc($roles)) {
    $roleOptions[$r['role_id']] = $r['role_types'];
}

$result = mysqli_query($con, "SELECT * FROM users");
?>

<!DOCTYPE html>
<html>
<head>
    <title>Manage Users</title>
    <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
</head>
<body class="w3-container dark-theme w3-padding">

<h2 class="w3-text-blue">User Management</h2>

<div class="w3-card w3-padding w3-margin-bottom">
    <form method="post" action="modify.php">
        <input type="hidden" name="action" value="add">
        <label>Username</label>
        <input class="w3-input w3-border" type="text" name="username" required>
        <label>Password</label>
        <input class="w3-input w3-border" type="password" name="password" required>
        <label>Role</label>
        <select class="w3-select w3-border" name="role_id" required>
            <option disabled selected value="">Select Role</option>
            <?php foreach ($roleOptions as $id => $name): ?>
                <option value="<?= $id ?>"><?= htmlspecialchars($name) ?></option>
            <?php endforeach; ?>
        </select>
        <button class="w3-button w3-green w3-margin-top" type="submit">Add User</button>
    </form>
</div>

<table class="w3-table w3-bordered w3-striped">
    <tr>
        <th>ID</th><th>Username</th><th>Role</th><th>Actions</th>
    </tr>
    <?php while ($row = mysqli_fetch_assoc($result)): ?>
        <tr>
            <form method="post" action="modify.php">
                <td><?= $row['user_id'] ?></td>
                <td><input class="w3-input" type="text" name="username" value="<?= htmlspecialchars($row['username']) ?>" required></td>
                <td>
                    <select class="w3-select" name="role_id">
                        <?php foreach ($roleOptions as $id => $name): ?>
                            <option value="<?= $id ?>" <?= $row['role_id'] == $id ? 'selected' : '' ?>><?= htmlspecialchars($name) ?></option>
                        <?php endforeach; ?>
                    </select>
                </td>
                <td>
                    <input type="hidden" name="user_id" value="<?= $row['user_id'] ?>">
                    <input type="hidden" name="action" value="edit">
                    <button class="w3-button w3-blue w3-small" type="submit">Update</button>
                    <a href="modify.php?delete=<?= $row['user_id'] ?>" onclick="return confirm('Delete this user?')" class="w3-button w3-red w3-small">Delete</a>
                </td>
            </form>
        </tr>
    <?php endwhile; ?>
</table>
</body>
</html>

<?php
mysqli_close($con);
?>
