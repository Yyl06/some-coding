<?php
// Retrieve the numbers from the form
$no1 = $_POST['no1'];
$no2 = $_POST['no2'];

// Check which button was pressed and perform the respective calculation
if (isset($_POST['addButton'])) {
    $result = $no1 + $no2;
    echo 'Result: ' . $result;
} elseif (isset($_POST['subtractButton'])) {
    $result = $no1 - $no2;
    echo 'Result: ' . $result;
} elseif (isset($_POST['multiplyButton'])) {
    $result = $no1 * $no2;
    echo 'Result: ' . $result;
} elseif (isset($_POST['divideButton'])) {
    // Check if division by zero occurs
    if ($no2 == 0) {
        echo 'Cannot divide by zero';
    } else {
        $result = $no1 / $no2;
        echo 'Result: ' . $result;
    }
}
?>