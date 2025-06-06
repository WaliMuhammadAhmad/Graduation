<?php
include_once 'db_config.php';
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Library System</title>
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
    <h1>Library Management System</h1>
    <a href="showStudents.php">Show Students</a><br><br>
    <a href="showBooks.php">Show Books</a><br><br>
    <a href="InsertStudent.php">Insert New Students</a><br><br>
    <a href="InsertBook.php">Insert New Books</a>
</body>

</html>