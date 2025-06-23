<?php
function addNewCust(){
    $name = $_POST['name'];
    $contact = $_POST['contact'];
    $email = $_POST['email'];
    $con = mysqli_connect('localhost', 'root', '', 'mydb');
    if(mysqli_connect_errno()){
        echo "Error connect to MYSQL" . mysqli_connect_error();
    }
    
    $sql = "INSERT INTO tables(name, contact, email) VALUES (?, ?, ?)";
    $stmt = $con->prepare($sql);
    $stmt->bind_param("sis", $name, $contact, $email);
    $stmt->execute();

    $stmt->close();
    $con->close();
}
?>