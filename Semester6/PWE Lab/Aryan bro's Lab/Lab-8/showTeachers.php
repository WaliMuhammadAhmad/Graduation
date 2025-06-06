<?php
include_once 'db_config.php';

$query = "SELECT * FROM teachers";
$result = mysqli_query($link,$query);
?>

<!DOCTYPE html>
<html>

<head>
    <title>Teacher Data</title>
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

    <h1>Teacher Data</h1>

    <table>
        <thead>
            <tr>
                <th>ID</th>
                <th>Name</th>
                <th>Department</th>
                <th>Contact Information</th>
                <th>Academic Rank</th>
            </tr>
        </thead>
        <tbody>
            <?php
        while ($row = $result->fetch_assoc()) {
            echo "<tr>";
            echo "<td>" . $row['ID'] . "</td>";
            echo "<td>" . $row['Name'] . "</td>";
            echo "<td>" . $row['Department'] . "</td>";
            echo "<td>" . $row['ContactInformation'] . "</td>";
            echo "<td>" . $row['AcademicRank'] . "</td>";
            echo "</tr>";
        }
        ?>
        </tbody>
    </table>

    <br>
    <a href="Home.php">Go back to Home</a>

</body>

</html>