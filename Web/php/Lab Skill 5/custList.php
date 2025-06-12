<!DOCTYPE html>
<html>
    <head>
        <title>Customer List</title>
        <style>
            table{
                width: 50%;
            }
            th, td{
                border: 1px solid black;
                padding: 8px;
                text-align: center;
            }
        </style>
    </head>
    <body>
        <h2>Customer List</h2>
        <table>
            <thead>
                <tr>
                    <th>Username</th>
                    <th>Password</th>
                    <th>Name</th>
                    <th>Email</th>
                    <th>Contact Number</th>
                </tr>
            </thead>
            <tbody>
                <?php
                include "Cust.php";
                if(isset($_POST['delete'])){
                    $toDelete = $_POST['delete_username'];
                    if(deleteCust($toDelete)){
                        echo "<p style='color:green;'>Customer deleted successfully.</p>";
                    }else{
                        echo "<p style='color:red;'>Failed to delete customer.</p>";
                    }
                }
                getListOfCust();
                ?>
            </tbody>
        </table>
    </body>
</html>