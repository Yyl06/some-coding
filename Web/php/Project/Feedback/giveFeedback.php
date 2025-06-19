<?php
session_start();
if (!isset($_SESSION['username'])) {
    header("Location: ../Login/login.php");
    exit;
}

$username = $_SESSION['username'];

$con = mysqli_connect('localhost', 'root', '', 'fbs');
if (mysqli_connect_errno()) {
    die("Connection failed: " . mysqli_connect_error());
}

$userstmt = $con->prepare("SELECT users_id FROM users WHERE username = ?");
$userstmt->bind_param("s", $username);
$userstmt->execute();
$userstmt->bind_result($user_id);
$userstmt->fetch();
$userstmt->close();

$sql = "SELECT b.booking_id, f.name, b.booking_date, b.start_time, b.end_time
        FROM booking b
        JOIN facility f ON b.facility_id = f.facility_id
        WHERE b.userid = ?
        AND b.booking_id NOT IN (SELECT booking_id FROM feedback)
        ORDER BY b.booking_date DESC";

$stmt = $con->prepare($sql);
$stmt->bind_param("i", $user_id);
$stmt->execute();
$result = $stmt->get_result();
?>

<!DOCTYPE html>
<html>
<head>
    <title>Give Feedback</title>
    <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
</head>

<body class="dark-theme">
    <div class="w3-container w3-padding-32">
        <h2 class="w3-text-blue">Submit Feedback</h2>
        <?php if ($result->num_rows > 0): ?>
            <form method="post" action="processFeedback.php" class="w3-card dark-theme w3-round w3-padding">
                <label><b>Choose Booking</b></label>
                <select name="booking_id" class="w3-select w3-margin-bottom" required>
                    <option value="" disabled selected>Select a booking</option>
                    <?php while ($row = $result->fetch_assoc()): ?>
                        <?php
                        $label = $row['name'] . " - " . $row['booking_date'] . " (" .
                            date("H:i", strtotime($row['start_time'])) . " to " .
                            date("H:i", strtotime($row['end_time'])) . ")";
                        ?>
                        <option value="<?php echo $row['booking_id']; ?>"><?php echo htmlspecialchars($label); ?></option>
                    <?php endwhile; ?>
                </select>

                <label><b>Rating (1–5)</b> <span class="w3-small w3-text-grey">(Optional)</span></label>
                <input type="number" name="rating" class="w3-input w3-margin-bottom" min="1" max="5" placeholder="e.g. 4">

                <label><b>Comments</b></label>
                <textarea name="comments" class="w3-input w3-margin-bottom" rows="4" placeholder="Say something about your experience..." required></textarea>

                <button class="w3-button w3-blue w3-round" type="submit">Submit Feedback</button>
            </form>
        <?php else: ?>
            <p class="w3-text-grey">You have no pending bookings for feedback.</p>
        <?php endif; ?>
    </div>
</body>
</html>

<?php
$stmt->close();
$con->close();
?>