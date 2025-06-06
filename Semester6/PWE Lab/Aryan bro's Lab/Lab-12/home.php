<?php
include 'config.php';
include 'functions.php';
checkLogin();
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

// Handle delete operation
if (isset($_GET['action']) && $_GET['action'] == 'delete' && isset($_GET['id'])) {
    $id = $_GET['id'];
    $sql = "DELETE FROM Students WHERE id = $id";
    mysqli_query($link, $sql);
    header("Location: home.php");
    exit();
}

// Handle update operation
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['update'])) {
    $id = $_POST['id'];
    $roll_number = $_POST['roll_number'];
    $name = $_POST['name'];
    $email = $_POST['email'];
    $home_address = $_POST['home_address'];
    $department = $_POST['department'];
    $room_allocated = $_POST['room_allocated'];

    $sql = "UPDATE Students SET
            roll_number = '$roll_number',
            name = '$name',
            email = '$email',
            home_address = '$home_address',
            department = '$department',
            room_allocated = '$room_allocated'
            WHERE id = $id";

    mysqli_query($link, $sql);
    header("Location: home.php");
    exit();
}

// Handle add student operation
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['add'])) {
    $roll_number = $_POST['roll_number'];
    $name = $_POST['name'];
    $email = $_POST['email'];
    $home_address = $_POST['home_address'];
    $department = $_POST['department'];
    $room_allocated = $_POST['room_allocated'];

    $sql = "INSERT INTO Students (roll_number, name, email, home_address, department, room_allocated)
            VALUES ('$roll_number', '$name', '$email', '$home_address', '$department', '$room_allocated')";

    mysqli_query($link, $sql);
    header("Location: home.php");
    exit();
}
?>

<!-- HTML content for admin home page -->
<!DOCTYPE html>
<html>

<head>
    <title>Home</title>
    <link rel="stylesheet" href="style.css">
</head>

<body>
    <h2>Welcome, <?php echo $_SESSION['admin_username']; ?>!</h2>
    <a href="logout.php" class="btn">Logout</a>
    <h3>Students</h3>

    <!-- Display students in a table -->
    <table border="1">
        <tr>
            <th>ID</th>
            <th>Roll Number</th>
            <th>Name</th>
            <th>Email</th>
            <th>Home Address</th>
            <th>Department</th>
            <th>Room Allocated</th>
            <th>Action</th>
        </tr>

        <?php
        $sql = "SELECT * FROM Students";
        $result = mysqli_query($link, $sql);

        while ($row = $result->fetch_assoc()) {
            echo "<tr>
                    <td>{$row['id']}</td>
                    <td>{$row['roll_number']}</td>
                    <td>{$row['name']}</td>
                    <td>{$row['email']}</td>
                    <td>{$row['home_address']}</td>
                    <td>{$row['department']}</td>
                    <td>{$row['room_allocated']}</td>
                    <td>
                        <a href='home.php?action=delete&id={$row['id']}'>Delete</a>
                        <a href='edit.php?id={$row['id']}'>Edit</a>
                    </td>
                </tr>";
        }
        ?>

    </table>

    <h3>Add New Student</h3>

    <!-- Form to add a new student -->
    <form method="post" action="">
        <label for="roll_number">Roll Number:</label>
        <input type="text" name="roll_number" required><br>

        <label for="name">Name:</label>
        <input type="text" name="name" required><br>

        <label for="email">Email:</label>
        <input type="email" name="email" required><br>

        <label for="home_address">Home Address:</label>
        <textarea name="home_address" required></textarea><br>

        <label for="department">Department:</label>
        <select name="department" required>
            <option value="CS">CS</option>
            <option value="SE">SE</option>
        </select><br>

        <label for="room_allocated">Room Allocated (1-10):</label>
        <input type="number" name="room_allocated" min="1" max="10" required><br>

        <!-- <label for="room_allocated">Room Allocated:</label>
        <input type="text" name="room_allocated" required><br> -->

        <input type="submit" name="add" value="Add Student">
    </form>
</body>

</html>