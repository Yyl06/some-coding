<?php
session_start();

// Show registration success alert
if (isset($_GET['registered']) && $_GET['registered'] === 'true'): ?>
    <script>
        alert("Registration successful! You may now log in.");
    </script>
<?php endif;

// Login processing block
if ($_SERVER['REQUEST_METHOD'] === 'POST') {

    $username = trim($_POST['username'] ?? "");
    $password = $_POST['password'] ?? "";

    $con = mysqli_connect('localhost', 'root', '', 'fbs');
    if (mysqli_connect_errno()) {
        die("Failed to connect to MySQL: " . mysqli_connect_error());
    }

    $stmt = $con->prepare("
        SELECT u.user_id, u.password, r.role_types, r.role_id
        FROM Users u
        JOIN Role r ON u.role_id = r.role_id
        WHERE u.username = ?
    ");

    $stmt->bind_param("s", $username);
    $stmt->execute();
    $stmt->store_result();

    if ($stmt->num_rows === 1) {
        $stmt->bind_result($user_id, $hashed_password, $role_type, $role_id);
        $stmt->fetch();
        $role_type = trim($role_type);

        if (password_verify($password, $hashed_password)){
            $_SESSION['user_id'] = $user_id;
            $_SESSION['username'] = $username;
            $_SESSION['role_type'] = $role_type;
            $_SESSION['role_id'] = $role_id;

            if ($role_type === 'Admin' || $role_type === 'Staff') {
                header("Location: ../Management/adminPanel.php");
                exit;
            } elseif ($role_type === 'Student' || $role_type === 'Guest') {
                header("Location: ../Booking/booking.php");
                exit;
            } else {
                echo "Invalid role type.";
                exit;
            }
        } else {
            echo "Incorrect password.";
            exit;
        }
    } else {
        echo "Username not found.";
        exit;
    }

    $stmt->close();
    $con->close();

} else {
    echo "Invalid access.";
    exit;
}
?>
