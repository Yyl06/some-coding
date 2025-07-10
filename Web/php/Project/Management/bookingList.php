<?php
session_start();

if (!isset($_SESSION['user_id']) || !in_array($_SESSION['role_id'], [1, 2])){
    echo "<script>alert('Access Denied. Admins only.'); window.location.href = '../Login/login.php';</script>";
    exit;
}

$con = mysqli_connect('localhost', 'root', '', 'fbs');
if(mysqli_connect_errno()){
    die("Connection failed: . mysqli_connect_error()");
}

$sql = "SELECT b.booking_id , f.type_id, ft.types, u.username, up.email, b.booking_date, b.start_time, b.end_time, b.booked_time, bs.current_status
FROM booking b
JOIN facility f ON b.facility_id = f.facility_id
JOIN facilitytypes ft ON f.type_id = ft.type_id
JOIN users u ON b.user_id = u.user_id
JOIN userprofile up ON u.user_id = up.user_id
JOIN bookingStatus bs ON b.status_id = bs.status_id
ORDER BY b.booking_date DESC, b.start_time DESC";

$result = mysqli_query($con, $sql);
?>

<!DOCTYPE html>
<html>
    <head>
        <title>All Bookings - Admin Panel</title>
        <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
        <link rel="stylesheet" href="../style.css">
    </head>
    <body class="dark-theme">
        <div class="w3-container w3-padding-32">
            <h2 class="w3-center w3-text-blue">All Bookings</h2>
            <div class="w3-card dark-theme w3-round w3-padding">
                <table class="w3-table w3-bordered w3-hoverable">
                    <thead class="w3-blue">
                        <tr>
                            <th>Facility</th>
                            <th>User</th>
                            <th>Email</th>
                            <th>Date</th>
                            <th>Start Time</th>
                            <th>End Time</th>
                            <th>Status</th>
                            <th>Action</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php
                        if ($result && mysqli_num_rows($result) > 0){
                            while($row = mysqli_fetch_assoc($result)){
                                echo "<tr>";
                                echo "<td>" . htmlspecialchars($row['types']) . "</td>";
                                echo "<td>" . htmlspecialchars($row['username']) . "</td>";
                                echo "<td>" . htmlspecialchars($row['email']) . "</td>";
                                echo "<td>" . htmlspecialchars($row['booking_date']) . "</td>";
                                echo "<td>" . htmlspecialchars(date("H:i", strtotime($row['start_time']))) . "</td>";
                                echo "<td>" . htmlspecialchars(date("H:i", strtotime($row['end_time']))) . "</td>";
                                echo "<td>" . htmlspecialchars($row['current_status']) . "</td>";
                                echo "<td>";

                                if($row['current_status'] == 'Pending'){
                                    echo "<form method='post' action='updateStatus.php' style='display:inline;'>
                                        <input type='hidden' name='booking_id' value='{$row['booking_id']}'>
                                        <button class='greenbutton w3-small' name='action' value='accept'>Accept</button>
                                    </form>";
                                    echo "<form method='post' action='updateStatus.php' style='display:inline;'>
                                        <input type='hidden' name='booking_id' value='{$row['booking_id']}'>
                                        <button class='redbutton w3-small' name='action' value='reject'>Reject</button>
                                    </form>";
                                }else{
                                    echo "<span class='w3-text-grey'>No Actions</span>";
                                }
                                echo "</td></tr>";
                            }
                        }else{
                            echo "<tr><td colspan='8' class='w3-center'>No Bookings Found.</td></tr>";
                        }
                        ?>
                    </tbody>
                </table>
            </div>
        </div>
    </body>
</html>
<?php
mysqli_close($con);
?>