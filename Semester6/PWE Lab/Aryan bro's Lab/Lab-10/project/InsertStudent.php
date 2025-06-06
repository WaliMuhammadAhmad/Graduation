<?php
include_once 'db_config.php';

if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['insert_student'])) {
    $rollNumber = $_POST["roll_number"];
    $name = $_POST["name"];
    $department = $_POST["department"];
    $program = $_POST["program"];
    $contactInformation = $_POST["contact_information"];

    $insertStudentQuery = "INSERT INTO students (RollNumber, Name, Department, Program, ContactInformation)
                           VALUES ('$rollNumber', '$name', '$department', '$program', '$contactInformation')";

    $result = mysqli_query($link, $insertStudentQuery);

    if ($result) {
        echo "Student inserted successfully!";
    } else {
        echo "Error: " . mysqli_error($link);
    }
}

if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['insert_book'])) {
    $isbn = $_POST["isbn"];
    $title = $_POST["title"];
    $author = $_POST["author"];
    $genre = $_POST["genre"];
    $availableCopies = $_POST["available_copies"];
    $totalCopies = $_POST["total_copies"];

    $insertBookQuery = "INSERT INTO books (ISBN, Title, Author, Genre, AvailableCopies, TotalCopies)
                        VALUES ('$isbn', '$title', '$author', '$genre', $availableCopies, $totalCopies)";

    $result = mysqli_query($link, $insertBookQuery);

    if ($result) {
        echo "Book inserted successfully!";
    } else {
        echo "Error: " . mysqli_error($link);
    }
}
?>

<!DOCTYPE html>
<html>

<head>
    <title>Insert Data</title>
    <style>
    a {
        width: 150px;
        font-size: larger;
        font-weight: 600;
        border: solid 2px;
        margin: 10px;
        padding: 5px;
        text-decoration: none;
        color: blue;
        background-color: lightblue;
    }
    </style>
</head>

<body>

    <h1>Insert Data</h1>

    <!-- Insert Student Form -->
    <h2>Insert New Student</h2>
    <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
        <label for="roll_number">Roll Number:</label>
        <input type="text" id="roll_number" name="roll_number" required><br>

        <label for="name">Name:</label>
        <input type="text" id="name" name="name" required><br>

        <label for="department">Department:</label>
        <input type="text" id="department" name="department"><br>

        <label for="program">Program:</label>
        <input type="text" id="program" name="program"><br>

        <label for="contact_information">Contact Information:</label>
        <input type="text" id="contact_information" name="contact_information"><br>

        <input type="submit" name="insert_student" value="Insert Student">
    </form>


    <br>
    <a href="ShowStudents.php">View Student Data</a> |
    <a href="Home.php">Go back to Home</a>

</body>

</html>