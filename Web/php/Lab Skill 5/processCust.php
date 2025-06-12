<?php
include "Cust.php";
if(isset($_POST['Register'])){
    $addCust = addNewCust();
    if($addCust){
        header("Location: regForm.php");
        exit();
    }else{
        echo "Failed to register customer. Please check the database connection and try again.";
    }
}
?>