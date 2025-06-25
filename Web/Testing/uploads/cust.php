<?php
function addNewCust(){
    $name = $_POST['name'];
    $email = $_POST['email'];
    $contact = $_POST['contact'];

    $con = mysqli_connect('localhost', 'root', '','mydb');
    if(mysqli_connect_errno()){
        echo ("Error Connectting: ") . mysqli_connect_error();
    }

    $stmt = $con->prepare("INSERT INTO customer(name, email, contact) VALUES (?, ?, ?)");
    $stmt->bind_param("ssi", $name, $email, $contact);
    $stmt->execute();

    $stmt->close();
    $con->close();
}
?>