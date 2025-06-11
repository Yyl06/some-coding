<?php
$Sales = $_GET['Sales'];
function getCommission($Sales){
    if($Sales <= 2000){
        return $Sales * 0.03;
    }else if($Sales > 2000 || $Sales < 5000){
        return $Sales * 0.05;
    }else{
        return $Sales * 0.07;
    }
}
$Total = getCommission($Sales) + $Sales;
echo "Sales Amount: RM".$Sales;
echo "<br>Commission: RM".getCommission($Sales);
echo "<br>Total Amount: RM".$Total;
?>