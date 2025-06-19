<?php
session_start();

if (!isset($_SESSION['user_id']) || !in_array($_SESSION['role_id'], [1, 2])) {
    echo "<script>alert('Access Denied. Admins only.'); window.location.href = '../Login/login.php';</script>";
    exit;
}
?>

<!DOCTYPE html>
<html>
    <head>
        <title>Admin dashboard</title>
        <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
        <link rel="stylesheet" href="../style.css">
    </head>
    <body class="dark-theme">
        <div class="w3-container w3-padding-32">
            <div class="w3-card dark-theme w3-round-large w3-padding">
                <h2 class="w3-center w3-text-blue ">Admin panel</h2>
                <div class="w3-bar w3-margin-top w3-round dark-theme">
                    <a href="bookingList.php" class="w3-bar-item w3-button w3-blue w3-margin-right">List of Booking</a>
                    <a href="feedback.php" class="w3-bar-item w3-button w3-green w3-margin-right">All Feedbacks</a>
                    <a href="generateReport.php" class="w3-bar-item w3-button w3-black">Generate Weekly Report</a>
                    <a href="../logout.php" class="w3-bar-item w3-button w3-red w3-right" onclick="return confirm('Are you sure you want to log out?')">Logout</a>
                </div>
                <div class="w3-panel w3-padding-16">
                    <p>Welcome, Admin</p>
                    <p>Use the buttons above to manage bookings, view feedback, and generate weekly usage reports.</p>
                </div>
            </div>
        </div>
    </body>
</html>