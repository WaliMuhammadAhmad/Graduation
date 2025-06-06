<?php
include 'config.php';
include 'functions.php';
checkLogin();

if (isset($_GET['id'])) {
    $id = $_GET['id'];
    $sql = "SELECT * FROM Students WHERE id = $id";
    $result = mysqli_query($link, $sql);
    $row = $result->fetch_assoc();
} else {
    header("Location: home.php");
    exit();
}
?>

<!-- HTML content for editing a student -->
<!DOCTYPE html>
<html>

<head>
    <title>Edit Student</title>
    <link rel="stylesheet" href="style.css">

</head>

<body>
    <h2>Edit Student</h2>

    <form method="post" action="home.php">
        <input type="hidden" name="id" value="<?php echo $row['id']; ?>">

        <label for="roll_number">Roll Number:</label>
        <input type="text" name="roll_number" value="<?php echo $row['roll_number']; ?>" required><br>

        <label for="name">Name:</label>
        <input type="text" name="name" value="<?php echo $row['name']; ?>" required><br>

        <label for="email">Email:</label>
        <input type="email" name="email" value="<?php echo $row['email']; ?>" required><br>

        <label for="home_address">Home Address:</label>
        <textarea name="home_address" required><?php echo $row['home_address']; ?></textarea><br>

        <label for="department">Department:</label>
        <select name="department" required>
            <option value="CS" <?php if ($row['department'] == 'CS') echo 'selected'; ?>>CS</option>
            <option value="SE" <?php if ($row['department'] == 'SE') echo 'selected'; ?>>SE</option>
        </select><br>

        <label for="room_allocated">Room Allocated:</label>
        <input type="text" name="room_allocated" value="<?php echo $row['room_allocated']; ?>" required><br>

        <input type="submit" name="update" value="Update">
    </form>
    <a href="home.php">Go Home</a>
</body>

</html>