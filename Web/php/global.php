<?php
$x = 10;
$y = 20;
add();
echo $total;
function add(){
    $GLOBALS['total'] = $GLOBALS['x'] + $GLOBALS['y'];
}
?>