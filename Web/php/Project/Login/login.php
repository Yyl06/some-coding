<?php
session_start();
if (isset($_GET['registered']) && $_GET['registered'] === 'true'): ?>
    <script>
        alert("Registration successful! You may now log in.");
    </script>
<?php endif;

if (isset($_POST['login'])){
    $username = $_POST['username'] ?? "";
    $password = $_POST['password'] ?? "";

    $con = mysqli_connect('localhost', 'root', '', 'fbs');
    if (mysqli_connect_errno()){
        die("Failed to connect to MySQL" . mysqli_connect_error());
    }

    $stmt = $con->prepare("SELECT u.password,r.role_type FROM Users u
                            JOIN Role r ON u.role_id = r.role_id
                            WHERE u.username = ?");
    $stmt->bind_param("s", $username);
    $stmt->execute();
    $stmt->store_result();

    if ($stmt->num_rows == 1){
        $stmt->bind_result($hashed_password, $role_type);
        $stmt->fetch();

        if (password_verify($password,$hashed_password)){
            
            $_SESSION['username'] = $username;
            $_SESSION['role_type'] = $role_type;

            if ($role_type == 'Admin' || $role_type == 'Staff'){
                header("Location: ../Management/Admin.php");
                exit;
            }else if($role_type == 'Student' || $role_type == 'Guest') {
                header("Location: ../Booking/Booking.php");
                exit;
            }else{
                echo " Invalid role type.";
                exit;
            }
        }else{
            echo " Incorrect password.";
            exit;
        }
    }else{
        echo " Username not found.";
        exit;
    }
    $stmt->close();
    $con->close();
}else{
    echo " Invalid access.";
}
?>