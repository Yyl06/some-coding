<!DOCTYPE html>
<html>
    <head>
        <?php
            if(isset($_POST['register'])){
                $con = mysqli_connect('localhost', 'web73n', 'web73Nxs', 'hrdb');
                if(mysqli_connect_errno()){
                    echo "Error Connection" . mysqli_connect_error();
                }
            }
        ?>
    </head>
    <body>
        <h1>New Client Registration</h1>
        <fieldset>
            <form method="post">
                <label for="email">Email: </label>
                <input type="email" name="email" id="email">
                <label for="password">Password</label>
                <input type="password" name="password" name="password">
                <label for="phone">Phone: </label>
                <input type="text" name="phone" id="phone">
                <label for="dob">Date Of Birth</label>
                <input type="date" name="dob" id="dob">
                <input type="submit" name="register" value="register" id="register">
            </form>
        </fieldset>
        <?php
        $email = $_POST['email'];
        $password = $_POST['password'];
        $phone = $_POST['phone'];
        $dob = $_POST['dob'];
        $sql = "INSERT INTO client(email, password, phone, dob)
        VALUES('$email', '$password', '$phone', '$dob')";
        $qry = mysqli_query($con, $sql);
        mysqli_close($con);
        ?>
    </body>
</html>