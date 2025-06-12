<!DOCTYPE html>
<html>
    <script>
        <?php
        function addNewCar(){
            $regNumber = $_POST['regNumber'];
            $brand = $_POST['brand'];
            $model = $_POST['model'];
            $regDate = $_POST['regDate'];
            $price = $_POST['price'];
            $engineType = $_POST['engineType'];
            $con = mysqli_connect('localhost','root','','car');

            if (mysqli_connect_errno()){
                echo "Failed to connect to MySQL: " . mysqli_connect_error();
            }

            $sql="INSERT INTO car(regNumber, brand, model, regDate, price, engineType) VALUES
            ('$regNumber', '$brand', '$model', '$regDate', '$price', '$engineType')";

            $qry = mysqli_query($con,$sql);
            mysqli_close($con);

            // echo $sql; // to display sql
            if(!$qry){return false; // error new car record was not added
            }else{
            return true;}
        }
        ?>
    </script>
</html>