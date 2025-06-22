<?php
session_start();

// Only allow logged-in users
if (!isset($_SESSION['user_id']) || !in_array($_SESSION['role_id'], [3, 4])) {
    echo "<script>alert('Access Denied. Students or Guests only.'); window.location.href = '../Login/login.php';</script>";
    exit;
}

$con = mysqli_connect('localhost', 'root', '', 'fbs');
if (mysqli_connect_errno()) {
    die("Failed to connect: " . mysqli_connect_error());
}

$user_id = $_SESSION['user_id'];

$sql = "SELECT f.name AS facility_name, b.booking_date, b.start_time, b.end_time, bs.current_status
        FROM booking b
        JOIN facility f ON b.facility_id = f.facility_id
        JOIN bookingstatus bs ON b.status_id = bs.status_id
        WHERE b.user_id = ?
        ORDER BY b.booking_date DESC, b.start_time DESC";

$stmt = $con->prepare($sql);
$stmt->bind_param("i", $user_id);
$stmt->execute();
$result = $stmt->get_result();
?>

<!DOCTYPE html>
<html>
<head>
    <title>My Bookings</title>
    <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
    <link rel="stylesheet" href="../style.css">
</head>
<body class="dark-theme">
    <div class="w3-container w3-padding-32">
        <h2 class="w3-text-blue">My Booking History</h2>
        <div class="w3-card dark-theme w3-round w3-padding">
            <?php if ($result->num_rows > 0): ?>
                <table class="w3-table w3-bordered">
                    <thead class="w3-blue">
                        <tr>
                            <th>Facility</th>
                            <th>Date</th>
                            <th>Start</th>
                            <th>End</th>
                            <th>Status</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php while ($row = $result->fetch_assoc()): ?>
                            <tr>
                                <td><?= htmlspecialchars($row['facility_name']) ?></td>
                                <td><?= htmlspecialchars($row['booking_date']) ?></td>
                                <td><?= date("H:i", strtotime($row['start_time'])) ?></td>
                                <td><?= date("H:i", strtotime($row['end_time'])) ?></td>
                                <td><?= htmlspecialchars($row['current_status']) ?></td>
                            </tr>
                        <?php endwhile; ?>
                    </tbody>
                </table>
            <?php else: ?>
                <p class="w3-text-grey">You haven’t made any bookings yet.</p>
            <?php endif; ?>
        </div>
    </div>
</body>
</html>

<?php
$stmt->close();
$con->close();
?>
