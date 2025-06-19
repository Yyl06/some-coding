<!DOCTYPE html>
<html>
    <head>
        <title>Register</title>
        <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
        <link rel="stylesheet" href="../style.css">
        <script src="register.js"></script>
    </head>
    <body class="dark-theme">
        <div class="w3-container w3-card dark-theme w3-padding-32 w3-round-large w3-margin-top w3-margin-bottom" style="width: 400px; margin: auto;">
            <h2 class="w3-center w3-text-blue">User Registration</h2>
            <form action="registerProcess.php" method="post" onsubmit="return validateForm()" class="w3-container w3-margin-top">
                <label class="w3-text-white"><b>First Name</b></label>
                <input type="text" class="w3-input w3-border w3-round" name="first_name" required>

                <label class="w3-text-white"><b>Last Name</b></label>
                <input class="w3-input w3-border w3-round" type="text" name="last_name">

                <label class="w3-text-white"><b>Email</b></label>
                <input class="w3-input w3-border w3-round" type="email" name="email" required>

                <label class="w3-text-white">Contact Number</label>
                <input class="w3-input w3-border w3-round" type="tel" name="contact_number" required pattern="[0-9]{10,15}" title="Enter a valid phone number">

                <label class="w3-text-white">Username</label>
                <input class="w3-input w3-border w3-round" type="text" placeholder="Enter username" name="username" required>

                <label class="w3-text-white">Password</label>
                    <div class="w3-row w3-margin-bottom">
                    <input class="w3-input w3-border w3-round" type="password" name="password" id="password" required>
                    <input class="w3-check w3-margin-top" type="checkbox" onclick="togglePassword()">
                    <label class="w3-small">Show Password</label>
                </div>

                <label class="w3-text-white"><b>Role</b></label>
                <select class="w3-select w3-border w3-round" name="role_id" required>
                    <option value="" disabled selected>Choose role</option>
                <?php
                    $con = mysqli_connect('localhost','root','','fbs');
                    $roles = mysqli_query($con, "SELECT role_id, role_types FROM Role");
                    while($row = mysqli_fetch_assoc($roles)) {
                        echo "<option value='" . $row['role_id']. "'>" . htmlspecialchars($row['role_types']) . "</option>";
                    }
                    mysqli_close($con);
                ?>
                </select>

                <button class="w3-button w3-blue w3-margin-top w3-round w3-block">Register</button>
                <p class="w3-center w3-small w3-margin-top">Already have an account? <a href="../Login/login.html">Login here</a></p>
            </form>
        </div>
    </body>
</html>