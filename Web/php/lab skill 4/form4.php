<!DOCTYPE html>
<html>
    <body>
        <form action="" method="post">
            <fieldset>
                Enter number 1:
                <br><input type="number" name="x" required><br>
                Enter number 2:
                <br><input type="number" name="y" required><br>
                <button type="submit" name="op" value="Add">Add</button>
                <button type="submit" name="op" value="Subtract">Subtract</button>
                <button type="submit" name="op" value="Multiply">Multiply</button>
                <button type="submit" name="op" value="Divide">Divide</button>
                <button type="submit" name="op" value="Clear">Clear</button>
                <br><br>
            </fieldset>

            <?php
            $x = $_POST['x'];
            $y = $_POST['y'];
            $op = $_POST['op'];

            switch ($op){
                case 'Add':
                    $result = $x = $y;
                    echo "Result: " . $result;
                    break;

                case "Subtract":
                    $result = $x - $y;
                    echo "Result: " . $result;
                    break;
                
                case "Multiply":
                    $result = $x *$y;
                    echo "Result: " . $result;
                    break;

                case "Divide":
                    $result = $x / $y;
                    echo "Result: " . $result;
                    break;

                case "Clear":
                    $x = '';
                    $y = '';
                    break;

                default:
                    echo "Invalid operation";
                    exit;
            }
            ?>
        </form>
    </body>
</html>