<?php
session_start();

if (!isset($_SESSION['user_id']) || ($_SESSION['role_id'] != 1 && $_SESSION['role_id'] != 2)) {
    echo "<script>alert('Access Denied. Admins only.'); window.location.href = '../Login/login.php';</script>";
    exit;
}

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $booking_id = $_POST['booking_id'] ?? null;
    $action = $_POST['action'] ?? '';

    if (!$booking_id || ($action !== 'approve' && $action !== 'reject')) {
        echo "<script>alert('Invalid request.'); window.location.href='bookingList.php';</script>";
        exit;
    }

    $status_id = ($action === 'approve') ? 2 : 3;

    $con = mysqli_connect('localhost', 'root', '', 'fbs');
    if (mysqli_connect_errno()) {
        die("Connection Failed." . mysqli_connect_error());
    }

    $sql = "UPDATE booking SET status_id = ? WHERE booking_id = ?";
    $stmt = $con->prepare($sql);
    $stmt->bind_param("ii", $status_id, $booking_id);

    if ($stmt->execute()) {
        echo "<script>alert('Booking status updated.'); window.location.href='bookingList.php';</script>";
    } else {
        echo "<script>alert('Failed to update status.'); window.location.href='bookingList.php';</script>";
    }

    $stmt->close();
    $con->close();
}else{
    echo "<script>alert('Invalid access.'); window.location.href='bookingList.php';</script>";
    exit;
}
?>