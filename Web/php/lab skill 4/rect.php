<!DOCTYPE html>
<html>
    <body>
        <form action="" method="GET">
            <fieldset>
                Length:<br><input type="number" name="Length" required><br>
                Width:<br><input type="number" name="Width" required><br>
                <input type="submit" name="addbutton" value="Calculate">
            </fieldset>
        </form>
        <?php
        $Length = $_GET['Length'];
        $Width = $_GET['Width'];
        $area = $Length * $Width;
        echo "Area of Rectangle: ".$area;
        ?>
    </body>
</html>