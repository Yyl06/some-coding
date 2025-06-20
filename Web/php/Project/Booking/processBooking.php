<?php
session_start();

// Ensure user is logged in
if (!isset($_SESSION['user_id'])) {
    echo "<script>alert('You must be logged in to book.'); window.location.href = '../Login/login.php';</script>";
    exit;
}

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $facility_id = $_POST['facility_id'];
    $user_id = $_SESSION['user_id'];
    $booking_date = $_POST['booking_date'];
    $start_time = $_POST['start_time'];
    $end_time = $_POST['end_time'];

    $startMinutes = strtotime($start_time);
    $endMinutes = strtotime($end_time);
    $diffMinutes = ($endMinutes - $startMinutes) / 60;

    if ($diffMinutes > 300) {
        echo "<script>alert('Booking cannot exceed 5 hours.'); window.history.back();</script>";
        exit;
    }

    $con = mysqli_connect('localhost', 'root', '', 'fbs');
    if (mysqli_connect_errno()) {
        echo "Failed to connect to MySQL: " . mysqli_connect_error();
        exit;
    }

    $chkque = "SELECT * FROM booking
                WHERE facility_id = ? AND booking_date = ?
                AND NOT (end_time <= ? OR start_time >= ?)";
    $stmt = $con->prepare($chkque);
    $stmt->bind_param("isss", $facility_id, $booking_date, $end_time, $start_time);
    $stmt->execute();
    $result = $stmt->get_result();

    if ($result->num_rows > 0) {
        echo "<script>alert('This time slot is already booked. Please choose a different time.'); window.history.back();</script>";
        $stmt->close();
        $con->close();
        exit;
    }
    $stmt->close();

    $sql = "INSERT INTO booking (facility_id, user_id, booking_date, start_time, end_time, status_id)
            VALUES (?, ?, ?, ?, ?, 1)";
    $stmt = $con->prepare($sql);
    $stmt->bind_param("iisss", $facility_id, $user_id, $booking_date, $start_time, $end_time);

    if ($stmt->execute()) {
        echo "<script>
                alert('Booking successful!');
                setTimeout(function() { window.location.href='../Booking/booking.php'; }, 500);
            </script>";
    } else {
        echo "Booking failed: " . $stmt->error;
    }

    $stmt->close();
    $con->close();
} else {
    echo "Invalid request method.";
    exit;
}
?>
