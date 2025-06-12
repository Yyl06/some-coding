<!DOCTYPE html>
<html>
<head>
    <title>Car Information Form</title>
    <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
</head>
<body>
    <h2 style="text-align: center"> Car Information Form </h2>
    <form class="w3-container" name="carInfoForm" action="processCar.php" onsubmit="return ValidationForm()" method="post" class="w3docs">
        <div>
            <label for="regNumber">Registration Number:</label>
            <input class="w3-input" type="text" id="regNumber" size="30" name="regNumber">
        </div>
        <div>
            <label>Select Brand</label>
            <select class="w3-select" type="text" value="" name="brand">
                <option></option>
                <option>Honda</option>
                <option>Nissan</option>
                <option>Proton</option>
                <option>Perodua</option>
            </select>
        </div>

        <div>
            <label for="model">Model:</label>
            <input class="w3-input" type="text" id="model" size="30" name="model">
        </div>
        <div>
            <label for="regDate">Registration Date:</label>
            <input class="w3-input" type="date" id="regDate" name="regDate">
        </div>
        <div>
            <label for="price">Price per day:</label>
            <input class="w3-input" type="number" id="price" step="0.01" name="price">
        </div>
        <div>
            <label>Select Engine type:</label>
            <select class="w3-select" type="text" value="" name="engineType">
                <option></option>
                <option>Petrol</option>
                <option>Diesel</option>
                <option>Hybrid</option>
                <option>Electric</option>
            </select>
        </div>
        <br>
        <div class="buttons">
            <input type="submit" value="Save" name="addCarButton">
            <input type="reset" value="Reset" name="Reset">
        </div>
    </form>

    <script>
        function ValidationForm() {
            //js example if regNumber and brand are compulsory input
            var regNumber = document.forms["carInfoForm"]["regNumber"];
            var brand = document.forms["carInfoForm"]["brand"];

            if (regNumber.value == "") {
                alert("Please enter car registration number.");
                regNumber.focus();
                return false;
            }
            if (brand.value == "") {
                alert("Please enter a valid brand.");
                brand.focus();
                return false;
            }
            return true;
        }
    </script>
</body>
</html>