<?php
include "carInfo.php";
include "car.php";
if(isset($_POST['addCarButton'])){
    $addCarResult = addNewCar();
    if($addCarResult){
        header("Location: carList.php");
        exit();
    }else {
        echo "Failed to add car. Please check the database connection and try again.";
    }
}
?>