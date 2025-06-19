<?php
session_start();
if (!isset($_SESSION['username']) || !in_array($_SESSION['role_type'], ['Admin', 'Staff'])) {
    header("Location: ../Login/login.php");
    exit;
}

$con = mysqli_connect('localhost', 'root', '', 'fbs');
if (mysqli_connect_errno()) {
    die("Failed to connect to MySQL: " . mysqli_connect_error());
}

$reportType = $_GET['type'] ?? 'daily';

if($reportType === 'weekly'){
    $sql = "SELECT WEEK(booking_date) AS week_num, YEAR(booking_date) AS year, f.name AS facility, COUNT(*) AS total
            FROM booking b
            JOIN facility f ON b.facility_id = f.facility_id
            GROUP BY year, week_num, facility
            ORDER BY year DESC, week_num DESC";
}else{
    $sql = "SELECT booking_date, f.name AS facility, COUNT(*) AS total
            FROM booking b
            JOIN facility f ON b.facility_id = f.facility_id
            GROUP BY booking_date, facility
            ORDER BY booking_date DESC";
}
$result = mysqli_query($con, $sql);
?>

<!DOCTYPE html>
<html>
<head>
    <title>Usage Report</title>
    <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
</head>
<body class="dark-theme">
    <div class="w3-container w3-padding-32">
        <h2 class="w3-text-blue">Facility Booking Report</h2>

        <div class="w3-bar w3-margin-bottom">
            <a href="?type=daily" class="w3-bar-item w3-button <?php echo ($reportType === 'daily') ? 'w3-blue' : 'dark-theme'; ?>">Daily Report</a>
            <a href="?type=weekly" class="w3-bar-item w3-button <?php echo ($reportType === 'weekly') ? 'w3-blue' : 'dark-theme'; ?>">Weekly Report</a>
        </div>

        <div class="w3-card dark-theme w3-padding w3-round">
            <table class="w3-table w3-bordered w3-striped">
                <thead class="w3-blue">
                    <tr>
                        <th><?php echo ($reportType === 'weekly') ? 'Year - Week' : 'Date'; ?></th>
                        <th>Facility</th>
                        <th>Total Bookings</th>
                    </tr>
                </thead>
                <tbody>
                    <?php if (mysqli_num_rows($result) > 0): ?>
                        <?php while ($row = mysqli_fetch_assoc($result)): ?>
                            <tr>
                                <td>
                                    <?php
                                    echo ($reportType === 'weekly')
                                        ? "{$row['year']} - Week {$row['week_num']}"
                                        : htmlspecialchars($row['booking_date']);
                                    ?>
                                </td>
                                <td><?php echo htmlspecialchars($row['facility']); ?></td>
                                <td><?php echo $row['total']; ?></td>
                            </tr>
                        <?php endwhile; ?>
                    <?php else: ?>
                        <tr><td colspan="3" class="w3-center">No data available.</td></tr>
                    <?php endif; ?>
                </tbody>
            </table>
        </div>
    </div>
</body>
</html>

<?php
mysqli_close($con);
?>