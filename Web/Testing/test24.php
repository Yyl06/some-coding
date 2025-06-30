<!DOCTYPE html>
<html>
    <body>
        <form method="post">
            <label for="price">Price: </label>
            <input type="number" id="price" name="price"><br>
            <label for="numOfRoom">Number Of Room: </label>
            <input type="number" id="numOfRoom" name="numOfRoom"><br>
            <input type="submit" value="check" name="check">
        </form>
        <?php
        if(isset($_POST['check'])){
            $price = $_POST['price'];
            $numOfRoom = $_POST['numOfRoom'];

            $total = $price * $numOfRoom;
            $tax = $total * 0.06;
            $taxTotal = $total + $tax;
            
            echo "<fieldset>";
            echo "<legend>Payment: </legend>";
            echo "<p>Total Price: </p><br> $total";
            echo "<hr>";
            echo "<p>Tax(6%): </p><br> $tax";
            echo "<hr>";
            echo "<p>Amount Due(Plus Tax): </p>  $taxTotal";
            echo "</fieldset>";
        }
        ?>
    </body>
</html>
