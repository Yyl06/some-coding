<?php
session_start();
if (!isset($_SESSION['username'])) {
    header("Location: ../Login/login.php");
    exit;
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Booking a Facility</title>
    <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
    <link rel="stylesheet" href="../style.css">
    <script src="booking.js" defer></script>
</head>
<body class="w3-dark-grey">
    <div class="w3-bar w3-dark-grey w3-padding" style="position: fixed; top: 0; width: 100%; z-index: 999;">
        <span class="w3-bar-item">Welcome, <?php echo $_SESSION['username']; ?>!</span>
        <a href="myBookings.php" class="w3-button w3-indigo w3-margin-top">View My Bookings</a>
        <a href="../logout.php" class="w3-bar-item w3-button w3-red w3-right">Logout</a>
    </div>

    <div class="w3-container w3-display-middle w3-card w3-dark-grey w3-padding-32 w3-round-large" style="width: 500px;">
        <h2 class="w3-center w3-text-blue">Book a Facility</h2>
        <form action="processBooking.php" method="post">

            <label class="w3-text-white"><b>Search Facility</b></label>
            <input class="w3-input w3-border w3-round w3-margin-bottom" type="text" id="facilitySearch" placeholder="Type to filter facilities...">

            <label class="w3-text-white"><b>Select Facility</b></label>
            <select class="w3-select w3-border w3-round" name="facility_id" id="facilityDropdown" required onchange="checkAvailabilityAndDuration()">
                <option value="" disabled selected>Choose a Facility</option>
                <?php
                $con = mysqli_connect('localhost', 'root', '', 'fbs');
                if (mysqli_connect_errno()) {
                    die("Connection failed: " . mysqli_connect_error());
                }

                $sql = "SELECT facility_id, name FROM facility WHERE status_id = 1";
                $result = mysqli_query($con, $sql);
                while ($row = mysqli_fetch_assoc($result)) {
                    echo "<option value='" . $row['facility_id'] . "'>" . htmlspecialchars($row['name']) . "</option>";
                }
                mysqli_close($con);
                ?>
            </select>

            <label class="w3-text-white"><b>Date</b></label>
            <input class="w3-input w3-border w3-round" type="date" name="booking_date" required onchange="checkAvailabilityAndDuration()">

            <label class="w3-text-white"><b>Start Time</b></label>
            <input class="w3-input w3-border w3-round" type="time" name="start_time" required onchange="checkAvailabilityAndDuration()">

            <label class="w3-text-white"><b>End Time</b></label>
            <input class="w3-input w3-border w3-round" type="time" name="end_time" required onchange="checkAvailabilityAndDuration()">

            <p id="availabilityMsg" class="w3-small w3-margin-top"></p>
            <button type="submit" class="w3-button w3-blue w3-margin-top w3-round w3-block">Book Now</button>
        </form>
    </div>
</body>
</html>
