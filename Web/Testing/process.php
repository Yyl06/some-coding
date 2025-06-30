<?php
if(isset($_GET['username'])){
    $username =  $_GET['username'];
    echo "Hello, " . htmlspecialchars($username);
}else{
    echo "No username provided.";
}
?>

<?php
$marks = array("1", "2", "3", "4", "5");
$total = 0;
$avg = 0;

foreach ($marks as $i) {
    echo "Mark: " . $i . "<br>";
    $total += $i;
}
echo "Total Marks: " . $total . "<br>";

foreach($marks as $i){
    $avg += $i;
}
$avg /= count($marks);
echo "Average Marks: " . $avg . "<br>";
?>

<?php
if($category == "C"){
    echo 'Cerificate level';
}else if ($category == "D"){
    echo 'Diploma level';
}else{
    echo 'Degree Level';
}

switch($category){
    case 'C':
        echo 'Cerificate level';
        break;
    case 'D':
        echo 'Diploma level';
        break;
    default:
        echo 'Degree Level';
}

?>