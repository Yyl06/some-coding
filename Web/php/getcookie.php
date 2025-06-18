<?php
if (isset($_COOKIE['user'])){
    echo "Welcome back, " . htmlspecialchars(($_COOKIE['user']));
}else{
    echo "No cookie found. ";
}
?>