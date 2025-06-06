<?php
include_once 'db_config.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $rollNumber = mysqli_real_escape_string($link, $_POST['rollNumber']);
    $name = mysqli_real_escape_string($link, $_POST['name']);
    $department = mysqli_real_escape_string($link, $_POST['department']);
    $program = mysqli_real_escape_string($link, $_POST['program']);
    $contactInformation = mysqli_real_escape_string($link, $_POST['contactInformation']);

    $updateQuery = "UPDATE students SET 
                    Name='$name', 
                    Department='$department', 
                    Program='$program', 
                    ContactInformation='$contactInformation' 
                    WHERE RollNumber='$rollNumber'";

    $updateResult = mysqli_query($link, $updateQuery);

    if ($updateResult) {
        echo "Student updated successfully!";
    } else {
        echo "Error: " . mysqli_error($link);
    }
}

if (isset($_GET['roll_number'])) {
    $rollNumber = $_GET['roll_number'];

    $selectQuery = "SELECT * FROM students WHERE RollNumber='$rollNumber'";
    $selectResult = mysqli_query($link, $selectQuery);

    if ($selectResult) {
        $row = mysqli_fetch_assoc($selectResult);
    } else {
        echo "Error: " . mysqli_error($link);
    }
}
?>

<!DOCTYPE html>
<html>

<head>
    <title>Update Student</title>
    <style>
    label {
        display: block;
        margin: 10px 0;
    }
    </style>
</head>

<body>

    <h1>Update Student</h1>

    <form method="post" action="">
        <label for="rollNumber">Roll Number:</label>
        <input type="text" name="rollNumber" value="<?php echo $row['RollNumber']; ?>" readonly>

        <label for="name">Name:</label>
        <input type="text" name="name" value="<?php echo $row['Name']; ?>" required>

        <label for="department">Department:</label>
        <input type="text" name="department" value="<?php echo $row['Department']; ?>">

        <label for="program">Program:</label>
        <input type="text" name="program" value="<?php echo $row['Program']; ?>">

        <label for="contactInformation">Contact Information:</label>
        <input type="text" name="contactInformation" value="<?php echo $row['ContactInformation']; ?>">

        <input type="submit" value="Update">
    </form>

    <br>
    <a href="ShowStudents.php">Go back to Student Data</a>

</body>

</html>