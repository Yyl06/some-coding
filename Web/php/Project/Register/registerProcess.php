<!DOCTYPE html>
<?php
function addNewUser(){
    $first_name = trim($_POST['first_name']);
    $last_name = trim($_POST['last_name']);
    $email = trim($_POST['email']);
    $contact = trim($_POST['contact_number']);
    $username = trim($_POST['username']);
    $password = password_hash($_POST['password'], PASSWORD_DEFAULT);
    $role_type = $_POST['role_id'];
    $con = mysqli_connect('localhost','root','','fbs');
    //register form
    if (empty($username) || empty($password) || empty($first_name) || empty($email) || empty($role_type)) {
        echo "Please fill in all required fields.";
        exit;
    }

    //Check if username or email already exists
    $check = mysqli_query($con, "SELECT * FROM Users u
    JOIN UserProfile p ON u.user_id = p.user_id
    WHERE u.username = '$username' OR p.email = '$email'");
    if (mysqli_num_rows($check) > 0) {
        echo "Username or email already in use.";
        exit;
    }

    if(mysqli_connect_errno()){
    echo "Failed to connect to MySQL:".mysqli_connect_error();
    }

    $sql1="INSERT INTO Users(username,password,role_id)
    VALUES ('$username', '$password', $role_type)";
    $qry1 = mysqli_query($con,$sql1);
    if(!$qry1){
        echo "Error: " . $sql1 . "<br>" . mysqli_error($con);
        exit;
    }

    $user_id = mysqli_insert_id($con); // Get the last inserted user ID
    $sql2 = "INSERT INTO userProfile(user_id, first_name, last_name, email, contact_number)
    VALUES ($user_id, '$first_name', '$last_name', '$email', '$contact')";
    $qry2 = mysqli_query($con, $sql2);
    if(!$qry2){
        echo "Error: " . $sql2 . "<br>" . mysqli_error($con);
        exit;
    }
    mysqli_close($con);
    header("Location: ../Login/login.html?registered=true");
    exit();
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    addNewUser();
}
?>