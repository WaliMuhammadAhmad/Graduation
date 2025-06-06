<?php
// Database connection configuration
$host = "localhost";
$username = "root";
$password = "";
$database = "lab-10";

$conn = new mysqli($host, $username, $password, $database);
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
?>
