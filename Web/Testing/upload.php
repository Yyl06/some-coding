<?php
error_reporting(E_ALL);
ini_set('display errors', 1);

if($_SERVER['REQUEST_METHOD'] == 'POST'){
    if(isset($_FILES['myfile']) && $_FILES['myfile']['error'] == 0){
        $filename = $_FILES['myfile']['name'];
        $tempname = $_FILES['myfile']['tmp_name'];
        $destfolder = "uploads";

        if(!is_dir($destfolder)){
            mkdir($destfolder, 0755, true);
        }

        $destination = $destfolder . "/" . $filename;
        if(move_uploaded_file($tempname, $destination)){
            echo "File uploaded";
        }else{
            echo "Failed to upload";
        }
    }else{
        echo "No file uploaded or error occurred";
    }
}
?>