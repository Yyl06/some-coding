<?php
session_start();
if(isset($_SESSION['username'])){
    echo " Welcome ". htmlspecialchars($_SESSION['username']);
}else{
    echo "Session is not set. <a href='session.php'>go to session page</a>";
}
?>