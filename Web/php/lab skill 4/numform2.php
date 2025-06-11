<!DOCTYPE html>
<html>
    <body>
        <form action="" method="post">
            <fieldset>
                Price:
                <br><input type="number" name="Salary" required><br>
                Tax rate(%):
                <br><input type="number" name="Rate" required><br>
                <input type="submit" name="addbutton" value="Calculate">
            </fieldset>
        </form>
        <?php
        $salary = $_POST['Salary'];
        $rate = $_POST['Rate'];
        $tax = $salary * ($rate / 100);
        $total = $salary + $tax;
        echo "Product Price: RM".$salary;
        echo "<br>Tax Rate: ".$tax;
        echo "<br>Total Price: RM".$total;
        ?>
    </body>
</html>