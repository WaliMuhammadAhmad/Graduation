<?php
include_once 'db_config.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $isbn = $_POST["isbn"];
    $title = $_POST["title"];
    $author = $_POST["author"];
    $genre = $_POST["genre"];
    $availableCopies = $_POST["available_copies"];
    $totalCopies = $_POST["total_copies"];

    $insertQuery = "INSERT INTO books (ISBN, Title, Author, Genre, AvailableCopies, TotalCopies)
                    VALUES ('$isbn', '$title', '$author', '$genre', $availableCopies, $totalCopies)";

    $result = mysqli_query($link, $insertQuery);

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
    <title>Insert New Book</title>
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

    <h1>Insert New Book</h1>

    <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
        <label for="isbn">ISBN:</label>
        <input type="text" id="isbn" name="isbn" required><br>

        <label for="title">Title:</label>
        <input type="text" id="title" name="title" required><br>

        <label for="author">Author:</label>
        <input type="text" id="author" name="author" required><br>

        <label for="genre">Genre:</label>
        <input type="text" id="genre" name="genre"><br>

        <label for="available_copies">Available Copies:</label>
        <input type="number" id="available_copies" name="available_copies" required><br>

        <label for="total_copies">Total Copies:</label>
        <input type="number" id="total_copies" name="total_copies" required><br>

        <input type="submit" value="Insert Book">
    </form>

    <br>
    <a href="ShowBooks.php">View Book Data</a> |
    <a href="Home.php">Go back to Home</a>

</body>

</html>