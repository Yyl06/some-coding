<?php
include "cust.php";

if(isset($_POST['register'])){
    $addCust = addNewCust();
    if($addCust){
        header("Location: form.html");
    }else{
        echo "Failed to register Customer.";
    }
}
?>