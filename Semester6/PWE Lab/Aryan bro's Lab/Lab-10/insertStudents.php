<?php
include_once 'db_config.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $roll_number = $_POST["roll_number"];
    $name = $_POST["name"];
    $department = $_POST["department"];
    $program = $_POST["program"];
    $contact_info = $_POST["contact_info"];

    $stmt = "INSERT INTO students (RollNumber, Name, Department, Program, ContactInformation) VALUES ($roll_number,$name,$department,$program,$contact_info)";

    $result = mysqli_query($link,$stmt);


    if ($result) {
        echo "Student record inserted successfully";
    }
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Insert Students</title>
</head>

<body>
    <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
        Roll Number: <input type="text" name="roll_number" required /><br />
        Name: <input type="text" name="name" required /><br />
        Department: <input type="text" name="department" /><br />
        Program: <input type="text" name="program" /><br />
        Contact Information: <input type="text" name="contact_info" /><br />
        <input type="submit" value="Insert Student" />
    </form>
</body>

</html>