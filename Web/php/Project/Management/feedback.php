<?php
session_start();
if (!isset($_SESSION['user_id']) || ($_SESSION['role_id'] != 1 && $_SESSION['role_id'] != 2)) {
    echo "<script>alert('Access Denied. Admins only.'); window.location.href = '../Login/login.php';</script>";
    exit;
}

$con = mysqli_connect('localhost', 'root', '', 'fbs');
if(mysqli_connect_errno()){
    die("Connection failed: " . mysqli_connect_error());
}

$sql = "SELECT f.name AS facility_name, b.booking_date, b.start_time, b.end_time,
                fb.rating, fb.comments, fb.created_when,
                up.first_name, up.last_name
        FROM feedback fb
        JOIN booking b ON fb.booking_id = b.booking_id
        JOIN facility f ON b.facility_id = f.facility_id
        JOIN users u ON b.user_id = u.user_id
        JOIN userprofile up ON u.user_id = up.user_id
        ORDER BY fb.created_when DESC";

$stmt = $con->prepare($sql);
$stmt->execute();
$result = $stmt->get_result();
?>

<!DOCTYPE html>
<html>
<head>
    <title>All Feedbacks - Admin Panel</title>
    <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
</head>
<body class="dark-theme">
    <div class="w3-container w3-padding-32">
        <h2 class="w3-text-blue">All Feedback Submissions</h2>

        <div class="w3-card dark-theme w3-round w3-padding">
            <?php if($result->num_rows > 0): ?>
                <table class="w3-table w3-bordered w3-striped w3-small">
                    <thead class="w3-blue">
                        <tr>
                            <th>User</th>
                            <th>Facility</th>
                            <th>Date</th>
                            <th>Time</th>
                            <th>Rating</th>
                            <th>Comment</th>
                            <th>Submitted</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php while($row = $result->fetch_assoc()): ?>
                            <tr>
                                <td><?php echo htmlspecialchars($row['first_name'] . ' ' . $row['last_name']); ?></td>
                                <td><?php echo htmlspecialchars($row['facility_name']); ?></td>
                                <td><?php echo htmlspecialchars($row['booking_date']); ?></td>
                                <td><?php echo date("H:i", strtotime($row['start_time'])) . " - " . date("H:i", strtotime($row['end_time'])); ?></td>
                                <td><?php echo $row['rating'] ?? '-'; ?></td>
                                <td><?php echo htmlspecialchars($row['comments'] ?? '-'); ?></td>
                                <td><?php echo date("d M Y H:i", strtotime($row['created_when'])); ?></td>
                            </tr>
                        <?php endwhile; ?>
                    </tbody>
                </table>
            <?php else: ?>
                <p class="w3-text-grey">No feedback has been submitted yet.</p>
            <?php endif; ?>
        </div>
    </div>
</body>
</html>

<?php
$stmt->close();
$con->close();
?>
