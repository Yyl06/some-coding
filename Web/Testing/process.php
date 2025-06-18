<?php
if(isset($_GET['username'])){
    $username =  $_GET['username'];
    echo "Hello, " . htmlspecialchars($username);
}else{
    echo "No username provided.";
}
?>  