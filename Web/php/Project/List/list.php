<!DOCTYPE html>
<?php
    session_start();
    if (!isset($_SESSION['user_id'])) {
        echo "<script>alert('You must be logged in to view bookings.'); window.location.href = '../Login/login.php';</script>";
        exit;
    }
    $user_id = $_SESSION['user_id'];
    $con = mysqli_connect('localhost', 'root', '', 'fbs');
    if (mysqli_connect_error()) {
        echo "<tr><td colspan='6'>Failed to connect to MySQL: " . mysqli_connect_error() . "</td></tr>";
    }
    $sql = "SELECT b.booking_id, f.facility_type, b.booking_date, b.start_time, b.end_time, bs.current_status
    FROM Booking b
    JOIN Facility f ON b.facility_id = f.facility_id
    JOIN bookingStatus bs ON b.status_id = bs.status_id
    WHERE b.user_id = ?
    ORDER BY b.booking_date DESC, b.start_time DESC";

    $stmt = $con->prepare($sql);
    $stmt->bind_param("i", $user_id);
    $stmt->execute();
    $result = $stmt->get_result();
?>

<html>
    <head>
            <title>Your Bookings</title>
            <link rel="stylesheet" href="../style.css">
            <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
            <script src="list.js"></script>
    </head>
    <body class="w3-light-grey">
        <div class="container w3-padding-32">
            <h2 class="w3-center w3-text-blue">Facility Bookings</h2>
            <div class="w3-card w3-white w3-round w3-padding">
                <table class="w3-table w3-bordered w3-striped w3-hoverable">
                    <thead>
                        <tr class="w3-blue">
                            <th>Facility</th>
                            <th>Date</th>
                            <th>Start Time</th>
                            <th>End Time</th>
                            <th>Status</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php
                            if($result->num_rows > 0) {
                                while($row = $result->fetch_assoc()){
                                    echo "<tr>";
                                    echo "<td>" . htmlspecialchars($row['facility_type']) . "</td>";
                                    echo "<td>" . htmlspecialchars($row['booking_date']) . "</td>";
                                    echo "<td>" . htmlspecialchars(date("H:i", strtotime($row['start_time']))) . "</td>";
                                    echo "<td>" . htmlspecialchars(date("H:i", strtotime($row['end_time']))) . "</td>";
                                    echo "<td>" . htmlspecialchars($row['current_status']) . "</td>";
                                    echo "</tr>";
                                }
                            }else{
                                echo "<tr><td colspan='5' class='w3-center'>No bookings found.</td></tr>";
                            }
                        ?>
                    </tbody>
                </table>
            </div>
        </div>
    </body>
</html>
<?php
    $stmt->close();
    $con->close();
?>