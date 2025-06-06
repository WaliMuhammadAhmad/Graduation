<?php
require 'db_config.php';
if (isset($_GET['delete_isbn'])) {
    $deleteISBN = $_GET['delete_isbn'];

    $deleteQuery = "DELETE FROM books WHERE ISBN = '$deleteISBN'";
    
    $deleteResult = mysqli_query($link, $deleteQuery);

    if ($deleteResult) {
        echo "Book deleted successfully!";
    } else {
        echo "Error: " . mysqli_error($link);
    }
}
include_once 'db_config.php';

$query = "SELECT * FROM books";
$result = mysqli_query($link, $query);
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

    <h1>Book Data</h1>

    <!-- <a href="InsertBook.php">Insert New Book</a> -->

    <table>
        <thead>
            <tr>
                <th>ISBN</th>
                <th>Title</th>
                <th>Author</th>
                <th>Genre</th>
                <th>Available Copies</th>
                <th>Total Copies</th>
                <th>Update</th>
                <th>Delete</th>
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

                echo "<td><a href='UpdateBook.php?isbn=" . $row['ISBN'] . "'>Update</a></td>";

                echo "<td><a href='#' onclick='confirmDelete(\"" . $row['ISBN'] . "\");'>Delete</a></td>";

                echo "</tr>";
            }
            ?>
        </tbody>
    </table>

    <br>
    <a href="Home.php">Go back to Home</a>

    <script>
    function confirmDelete(isbn) {
        if (confirm("Are you sure you want to delete this book?")) {
            window.location.href = 'ShowBooks.php?delete_isbn=' + isbn;
        }
    }
    </script>

</body>

</html>