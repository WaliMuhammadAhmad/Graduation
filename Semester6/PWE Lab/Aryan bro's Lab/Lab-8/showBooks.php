<?php
include_once 'db_config.php';

$query = "SELECT * FROM books";
$result = mysqli_query($link,$query);
?>

<!DOCTYPE html>
<html>

<head>
    <title>Book Data</title>
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

    <h1>Book Data</h1>

    <table>
        <thead>
            <tr>
                <th>ISBN</th>
                <th>Title</th>
                <th>Author</th>
                <th>Genre</th>
                <th>Available Copies</th>
                <th>Total Copies</th>
            </tr>
        </thead>
        <tbody>
            <?php
        while ($row = $result->fetch_assoc()) {
            echo "<tr>";
            echo "<td>" . $row['ISBN'] . "</td>";
            echo "<td>" . $row['Title'] . "</td>";
            echo "<td>" . $row['Author'] . "</td>";
            echo "<td>" . $row['Genre'] . "</td>";
            echo "<td>" . $row['AvailableCopies'] . "</td>";
            echo "<td>" . $row['TotalCopies'] . "</td>";
            echo "</tr>";
        }
        ?>
        </tbody>
    </table>

    <br>
    <a href="Home.php">Go back to Home</a>

</body>

</html>