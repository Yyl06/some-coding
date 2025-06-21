<?php
if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $facility_id = $_POST['facility_id'] ?? null;
    $booking_date = $_POST['booking_date'] ?? null;
    $start_time = $_POST['start_time'] ?? null;
    $end_time = $_POST['end_time'] ?? null;

    if (!$facility_id || !$booking_date || !$start_time || !$end_time) {
        echo "error";
        exit;
    }

    $con = mysqli_connect("localhost", "root", "", "fbs");
    if (!$con) {
        echo "error";
        exit;
    }

    $query = "SELECT * FROM booking
                WHERE facility_id = ?
                AND booking_date = ?
                AND NOT (end_time <= ? OR start_time >= ?)";

    $stmt = $con->prepare($query);
    $stmt->bind_param("isss", $facility_id, $booking_date, $start_time, $end_time);
    $stmt->execute();
    $result = $stmt->get_result();

    echo ($result->num_rows > 0) ? "unavailable" : "available";

    $stmt->close();
    $con->close();
} else {
    echo "error";
}
