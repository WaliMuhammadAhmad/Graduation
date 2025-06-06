<?php
include_once 'db_config.php';

$query = "SELECT * FROM students";
$result = mysqli_query($link,$query);
?>

<!DOCTYPE html>
<html>

<head>
    <title>Student Data</title>
    <style>
    table,
    th,
    td {
        border: 1px solid black;
        border-collapse: collapse;
        padding: 5px;
    }
    </style>
</head>

<body>

    <h1>Student Data</h1>

    <table>
        <thead>
            <tr>
                <th>Roll Number</th>
                <th>Name</th>
                <th>Department</th>
                <th>Program</th>
                <th>Contact Information</th>
            </tr>
        </thead>
        <tbody>
            <?php
        while ($row = $result->fetch_assoc()) {
            echo "<tr>";
            echo "<td>" . $row['RollNumber'] . "</td>";
            echo "<td>" . $row['Name'] . "</td>";
            echo "<td>" . $row['Department'] . "</td>";
            echo "<td>" . $row['Program'] . "</td>";
            echo "<td>" . $row['ContactInformation'] . "</td>";
            echo "</tr>";
        }
        ?>
        </tbody>
    </table>

    <br>
    <a href="Home.php">Go back to Home</a>

</body>

</html>