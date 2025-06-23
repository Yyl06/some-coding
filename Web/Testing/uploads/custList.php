<?php
$con = mysqli_connect('localhost', 'root', '', 'mydb');
    if(mysqli_connect_errno()){
        echo "Error connect to MYSQL" . mysqli_connect_error();
    }

    $sql = "SELECT * FROM tables";
    $result = $con->query($sql);
    while ($row = $result->fetch_assoc()) {
        echo "<tr>";
        echo "<td>" . $row['name'] . " - " . $row['contact'] . " - " . $row['email'] . "<br></td>";
        echo "</tr>";
    }

    $stmt->close();
    $con->close();
?>