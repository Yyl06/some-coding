<!DOCTYPE html>
<html>
    <head>
        <title>Car List</title>
        <style>
            table{
                width: 100%;
                border-collapse: collapse;
            }
            th, td{
                border: 1px solid black;
                padding: 8px;
                text-align: left;
            }
        </style>
    </head>
    <body>
        <h2>Car List</h2>
        <table>
            <thead>
                <tr>
                    <th>Reg Number</th>
                    <th>Brand</th>
                    <th>Model</th>
                    <th>Reg Date</th>
                    <th>Engine Type</th>
                </tr>
            </thead>
            <tbody>
                <?php
                $con = mysqli_connect('localhost', 'root', '','car');
                if(mysqli_connect_errno()){
                    echo "Failed to connect to MYSQL: ". mysqli_connect_error();
                }
                $sql = "SELECT * FROM car";
                $result = mysqli_query($con, $sql);
                if(mysqli_num_rows($result) > 0){
                    while($row = mysqli_fetch_assoc($result)){
                        echo "<tr>";
                        echo "<td>" . $row['regNumber'] . "</td>";
                        echo "<td>" . $row['brand'] . "</td>";
                        echo "<td>" . $row['model'] . "</td>";
                        echo "<td>" . $row['regDate'] . "</td>";
                        echo "<td>" . $row['price'] . "</td>";
                        echo "<td>" . $row['engineType'] . "</td>";
                        echo "</tr>";
                    }
                }else{
                    echo "<tr><td colspan='6'>No records found</td></tr>";
                }
                mysqli_close($con);
                ?>
            </tbody>
        </table>
    </body>
</html>