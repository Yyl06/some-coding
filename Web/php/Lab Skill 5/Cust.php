<!DOCTYPE html>
<html>
    <?php
    function addNewCust(){
        $name = $_POST['Name'];
        $email = $_POST['Email'];
        $contact = $_POST['Contact'];
        $userName = $_POST['Username'];
        $password = $_POST['Password'];
        $connection = mysqli_connect('localhost', 'root', '', 'customer');

        if(mysqli_connect_errno()){
            echo "Failed to connect to MYSQL: " . mysqli_connect_error();
        }

        $sql = "INSERT INTO customer(username, password, name, email, contactNumber) VALUES
        ('$userName', '$password', '$name', '$email', '$contact')";
        $query = mysqli_query($connection,$sql);
        mysqli_close($connection);

        if(!$query){
            return false;
        }else{
            return true;
        }
    }

    function getListOfCust(){
        $connect = mysqli_connect('localhost', 'root', '', 'customer');
        if(mysqli_connect_errno()){
            echo "Failed to connect to MYSQL: " . mysqli_connect_error();
        }
        $sql = "SELECT * FROM customer";
                $result = mysqli_query($connect, $sql);
                if(mysqli_num_rows($result) > 0){
                    while($row = mysqli_fetch_assoc($result)){
                        echo "<tr>";
                        echo "<td>" . $row['username'] . "</td>";
                        echo "<td>" . $row['password'] . "</td>";
                        echo "<td>" . $row['name'] . "</td>";
                        echo "<td>" . $row['email'] . "</td>";
                        echo "<td>" . $row['contactNumber'] . "</td>";
                        echo "<td>
                            <form method='post' style='display:inline'>
                                <input type='hidden' name='delete_username' value='" . $row['username'] . "'>
                                <input type='submit' name='delete' value='Delete' onclick=\"return confirm('Are you sure you want to delete this record?');\">
                            </form>
                        </td>";
                        echo "<tr>";
                    }
                }else{
                    echo "<tr><td colspan='6'>No records found</td></tr>";
                }
                mysqli_close($connect);
    }

    function deleteCust($userName){
        $connection = mysqli_connect('localhost', 'root', '', 'customer');
        if(mysqli_connect_errno()){
            echo "Failed to connect to MYSQL: " . mysqli_connect_error();
        }
        //Either use $sql = $connection->prepare("DELETE FROM customer WHERE id = ?") or use mysqli_prepare()
        $sql = mysqli_prepare($connection, "DELETE FROM customer WHERE username = ?");
        //stmt_bind_param() binds the variable $id to the prepared statement, preventing SQL injection
        // "i" indicates that the variable is an integer
        mysqli_stmt_bind_param($sql, "s", $userName);

        $result = mysqli_stmt_execute($sql);
        mysqli_stmt_close($sql);
        mysqli_close($connection);

        return $result;
    }
    ?>
</html>