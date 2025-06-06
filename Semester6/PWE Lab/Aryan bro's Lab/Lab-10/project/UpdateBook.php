<?php
include_once 'db_config.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $isbn = mysqli_real_escape_string($link, $_POST['isbn']);
    $title = mysqli_real_escape_string($link, $_POST['title']);
    $author = mysqli_real_escape_string($link, $_POST['author']);
    $genre = mysqli_real_escape_string($link, $_POST['genre']);
    $availableCopies = mysqli_real_escape_string($link, $_POST['availableCopies']);
    $totalCopies = mysqli_real_escape_string($link, $_POST['totalCopies']);

    $updateQuery = "UPDATE books SET 
                    Title='$title', 
                    Author='$author', 
                    Genre='$genre', 
                    AvailableCopies='$availableCopies', 
                    TotalCopies='$totalCopies' 
                    WHERE ISBN='$isbn'";

    $updateResult = mysqli_query($link, $updateQuery);

    if ($updateResult) {
        echo "Book updated successfully!";
    } else {
        echo "Error: " . mysqli_error($link);
    }
}

if (isset($_GET['isbn'])) {
    $isbn = $_GET['isbn'];

    $selectQuery = "SELECT * FROM books WHERE ISBN='$isbn'";
    $selectResult = mysqli_query($link, $selectQuery);

    if ($selectResult) {
        $row = mysqli_fetch_assoc($selectResult);
    } else {
        echo "Error: " . mysqli_error($link);
    }
}
?>

<!DOCTYPE html>
<html>

<head>
    <title>Update Book</title>
    <style>
    label {
        display: block;
        margin: 10px 0;
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

    <h1>Update Book</h1>

    <form method="post" action="">
        <label for="isbn">ISBN:</label>
        <input type="text" name="isbn" value="<?php echo $row['ISBN']; ?>" readonly>

        <label for="title">Title:</label>
        <input type="text" name="title" value="<?php echo $row['Title']; ?>" required>

        <label for="author">Author:</label>
        <input type="text" name="author" value="<?php echo $row['Author']; ?>" required>

        <label for="genre">Genre:</label>
        <input type="text" name="genre" value="<?php echo $row['Genre']; ?>">

        <label for="availableCopies">Available Copies:</label>
        <input type="number" name="availableCopies" value="<?php echo $row['AvailableCopies']; ?>" required>

        <label for="totalCopies">Total Copies:</label>
        <input type="number" name="totalCopies" value="<?php echo $row['TotalCopies']; ?>" required>

        <input type="submit" value="Update">
    </form>

    <br>
    <a href="ShowBooks.php">Go back to Book Data</a>

</body>

</html>