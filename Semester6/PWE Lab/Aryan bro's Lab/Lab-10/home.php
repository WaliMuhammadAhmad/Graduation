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
        color: wheat;
        background-color: navy;
    }
    </style>
</head>

<body>
    <h1>Library Management System</h1>
    <a href="insertStudents.php">Insert New Students</a><br><br>
    <a href="insertBooks.php">Insert New Books</a><br><br>
    <a href="showStudents.php">Show Students</a><br><br>
    <a href="showBooks.php">Show Books</a>
</body>

</html>