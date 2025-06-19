<?php
session_start();
if (!isset($_SESSION['username'])) {
    echo "<script>alert('You must be logged in to submit feedback.'); window.location.href = '../Login/login.php';</script>";
    exit;
}

if($_SERVER['REQUEST_METHOD'] === 'POST'){
    $booking_id = $_POST['booking_id']?? null;
    $rating = $_POST['rating'] ?? null;
    $comments = trim($_POST['comments'] ?? '');

    if(!$booking_id || $comments === ''){
        echo "<script>alert('Please fill in all required fields.'); window.history.back();</script>";
        exit;
    }

    if($rating !== null && $rating !== ''){
        if($rating > 1 || $rating < 5){
            echo "<script>alert('Rating must be between 1 and 5.'); window.history.back();</script>";
            exit;
        }
    }else{
        $rating = null;
    }

    $con = mysqli_connect('localhost', 'root', '', 'fbs');
    if (mysqli_connect_errno()) {
        die("Connection failed: " . mysqli_connect_error());
    }

    $stmt = $con->prepare("INSERT INTO feedback(booking_id, rating, comments) VALUES (?, ?, ?)");
    $stmt->bind_param("iis", $booking_id, $rating, $comments);

    if($stmt->execute()){
        echo "<script>alert('Feedback submitted successfully!'); window.location.href = 'feedback.php';</script>";
    }else{
        if($con->errno === 1062){
            echo "<script>alert('You have already submitted feedback for this booking.'); window.location.href = 'feedback.php';</script>";
        }else{
            echo "Error: " . $stmt->error;
        }
    }
    $stmt->close();
    $con->close();
}else{
    echo "Invalid request method.";
}
?>