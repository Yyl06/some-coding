<?php
session_start();
if ($_SERVER["REQUEST_METHOD"] == "POST"){
    $facility_id = $_POST['facility_id'];
    $user_id = $_POST['user_id'] ?? null;
    $booking_date = $_POST['booking_date'];
    $start_time = $_POST['start_time'];
    $end_time = $_POST['end_time'];

    if(!$user_id){
        die("User Not Logged In");
    }

    $startMinutes = strtotime($start_time);
    $endMinutes = strtotime($end_time);
    $diffMinutes = ($endMinutes - $startMinutes) / 60;
    if ($diffMinutes > 300) {
        echo "<script>alert('Booking cannot exceed 5 hours.'); window.history.back();</script>";
        exit;
    }


    $start_datetime = $booking_date . ' ' . $start_time;
    $end_datetime = $booking_date . ' ' . $end_time;

    $con = mysqli_connect('localhost','root','','fbs');
    if(mysqli_connect_errno()){
    echo "Failed to connect to MySQL:".mysqli_connect_error();
    }

    $chkque = "SELECT * FROM booking
    WHERE facility_id = ? AND booking_date = ?
    AND( (start_time < ? AND end_time > ?) OR
    (start_time >= ? AND end_time < ?)
    )";
    $stmt = $con->prepare($chkque);
    $stmt->bind_param("issss", $facility_id, $booking_date, $end_datetime, $start_datetime, $start_datetime, $end_datetime);
    $stmt->execute();
    $result = $stmt->get_result();
    if($result->num_rows > 0){
        echo "<script>alert('This time slot is already booked. Please choose a different time.'); window.history.back();</script>";
        exit;
    }
    $stmt->close();

    $sql1="INSERT INTO booking(facility_id, user_id, booking_date, start_time, end_time, status_id)
    VALUES(?, ?, ?, ?, ?, 1)";
    $stmt = $con->prepare($sql1);
    $stmt->bind_param("iisss", $facility_id, $user_id, $booking_date, $start_datetime, $end_datetime);
    if($stmt->execute()){
        echo "<script>alert('Booking successful!'); window.location.href='../Booking/booking.html';</script>";
    }else{
        echo "Booking failed: " . $stmt->error;
    }
    $stmt->close();
    $con->close();
}else{
    echo "Invalid request method.";
    exit;
}
?>