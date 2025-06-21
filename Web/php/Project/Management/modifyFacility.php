<?php
session_start();

if (!isset($_SESSION['user_id']) || !in_array($_SESSION['role_id'], [1, 2])){
    echo "<script>alert('Access Denied.'); window.location.href='../Login/login.php';</script>";
    exit;
}

$user_id = $_SESSION['user_id'];

$con = mysqli_connect('localhost', 'root', '', 'fbs');
if(!$con){
    die("Connection failed: " . mysqli_connect_error());
}

if ($_SERVER["REQUEST_METHOD"] === "POST"){
    $action = $_POST['action'];
    $name = $_POST['name'];
    $type_id = $_POST['type_id'];
    $status_id = $_POST['status_id'];

    if($action === 'add'){
        $stmt = $con->prepare("INSERT INTO facility(name, added_by, type_id, status_id) VALUES (?, ?, ?, ?)");
        $stmt->bind_param("siii", $name, $user_id, $type_id, $status_id);
    }else if($action === 'edit'){
        $facility_id = $_POST['facility_id'];
        $stmt = $con->prepare("UPDATE facility SET name = ?, type_id = ?, status_id = ? WHERE facility_id = ?");
        $stmt->bind_param("siii", $name, $type_id, $status_id, $facility_id);
    }

    $stmt->execute();
    header("Location: modifyFacility.php");
    echo "<script>alert('Facility added/updated successfully!'); window.location.href='modifyFacility.php';</script>";
    exit;
}

if(isset($_GET['delete'])){
    $id = $_GET['delete'];
    $stmt = $con->prepare("DELETE FROM facility WHERE facility_id = ?");
    $stmt->bind_param("i", $id);
    $stmt->execute();
    header("Location: modifyFacility.php");
}

$facilities = mysqli_query($con, "SELECT f.*, ft.facility_types, fs.facility_status
                                FROM facility f
                                JOIN facilitytypes ft ON f.type_id = ft.type_id
                                JOIN facilitystatus fs ON f.status_id = fs.status_id
                                ");

$types = mysqli_query($con, "SELECT * FROM facilitytypes");
$statuses = mysqli_query($con, "SELECT * FROM facilitystatus");
?>

<!DOCTYPE html>
<html>
<head>
    <title>Manage Facilities</title>
    <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
</head>
<body class="w3-container dark-theme w3-padding">
    <h2 class="w3-text-blue">Facility Management</h2>

    <div class="w3-card w3-padding w3-margin-bottom">
        <form method="post" action="">
            <input type="hidden" name="action" value="add">
            <label>Facility Name:</label>
            <input class="w3-input w3-border" name="name" required>

            <label>Type:</label>
            <select class="w3-select w3-border" name="type_id" required>
                <option value="" disabled selected>Choose Type</option>
                <?php
                mysqli_data_seek($types, 0);
                while($t = mysqli_fetch_assoc($types)):
                ?>
                    <option value="<?= $t['type_id'] ?>"><?= htmlspecialchars($t['facility_types']) ?></option>
                <?php endwhile; ?>
            </select>

            <label>Status:</label>
            <select class="w3-select w3-border" name="status_id" required>
                <option value="" disabled selected>Choose Status</option>
                <?php
                mysqli_data_seek($statuses, 0);
                while($s = mysqli_fetch_assoc($statuses)):
                ?>
                    <option value="<?= $s['status_id'] ?>"><?= htmlspecialchars($s['facility_status']) ?></option>
                <?php endwhile; ?>
            </select>

            <button class="w3-button w3-green w3-margin-top" type="submit">Add Facility</button>
        </form>
    </div>

    <div class="w3-margin-bottom">
    <input class="w3-input w3-border w3-round" type="text" id="searchInput" placeholder="Search by facility name or type..." onkeyup="filterTable()">
    </div>

    <table class="w3-table w3-bordered w3-striped">
        <thead class="w3-blue">
            <tr>
                <th>ID</th>
                <th>Name</th>
                <th>Type</th>
                <th>Status</th>
                <th>Actions</th>
            </tr>
        </thead>
        <tbody>
            <?php while($f = mysqli_fetch_assoc($facilities)): ?>
                <tr>
                    <form method="post" action="">
                        <td><?= $f['facility_id'] ?></td>
                        <td><input class="w3-input" type="text" name="name" value="<?= htmlspecialchars($f['name']) ?>"></td>
                        <td>
                            <select name="type_id" class="w3-select">
                                <?php
                                mysqli_data_seek($types, 0);
                                while($t = mysqli_fetch_assoc($types)):
                                ?>
                                    <option value="<?= $t['type_id'] ?>" <?= $t['type_id'] == $f['type_id'] ? 'selected' : '' ?>>
                                        <?= htmlspecialchars($t['facility_types']) ?>
                                    </option>
                                <?php endwhile; ?>
                            </select>
                        </td>
                        <td>
                            <select name="status_id" class="w3-select">
                                <?php
                                mysqli_data_seek($statuses, 0);
                                while($s = mysqli_fetch_assoc($statuses)):
                                ?>
                                    <option value="<?= $s['status_id'] ?>" <?= $s['status_id'] == $f['status_id'] ? 'selected' : '' ?>>
                                        <?= htmlspecialchars($s['facility_status']) ?>
                                    </option>
                                <?php endwhile; ?>
                            </select>
                        </td>
                        <td>
                            <input type="hidden" name="facility_id" value="<?= $f['facility_id'] ?>">
                            <input type="hidden" name="action" value="edit">
                            <button class="w3-button w3-blue w3-small" type="submit">Update</button>
                            <a class="w3-button w3-red w3-small" href="?delete=<?= $f['facility_id'] ?>" onclick="return confirm('Delete this facility?')">Delete</a>
                        </td>
                    </form>
                </tr>
            <?php endwhile; ?>
        </tbody>
    </table>
    <script>
        function filterTable() {
            const input = document.getElementById("searchInput").value.toLowerCase();
            const rows = document.querySelectorAll("table tbody tr");

            rows.forEach(row => {
            const name = row.cells[1]?.textContent.toLowerCase();
            const type = row.cells[2]?.textContent.toLowerCase();
            row.style.display = (name.includes(input) || type.includes(input)) ? "" : "none";
            });
        }
    </script>
</body>
</html>

<?php
mysqli_close($con);
?>