<!DOCTYPE html>
<html>
    <head>
        <title>Customer Registration</title>
        <script>
            function ValidationForm(){
                var userName = document.forms['regForm']['Username'];
                var password = document.forms['regForm']['Password'];

                if(userName.value == ""){
                    alert("Username must be filled.");
                    userName.focus();
                    return false;
                }
                if(password.value == ""){
                    alert("Password must be filled.");
                    password.focus();
                    return false;
                }
            }
        </script>
    </head>
    <body>
        <h2>Customer Registration</h2>
        <?php
        
        ?>
        <fieldset>
            <form action="processCust.php" onsubmit="return ValidationForm()" method="post" name="regForm">
                <label for="Name">Name</label>
                <input type="text" name="Name" required size="30"><br><br>
                <label for="Email">Email</label>
                <input type="text" name="Email" required size="30"><br><br>
                <label for="Contact">Contact Number</label>
                <input type="tel" name="Contact" required placeholder="012-3456789"><br><br>

                <label for="Username">Username: </label>
                <input type="text" name="Username" required><br><br>
                <label for="Password">Password: </label>
                <input type="password" name="Password" required><br><br>

                <input type="submit" name="Register" value="Save">
                <input type="reset" value="Reset">
            </form>
        </fieldset>
    </body>
</html>