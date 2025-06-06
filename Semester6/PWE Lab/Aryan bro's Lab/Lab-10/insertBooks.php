<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Insert Books</title>
</head>

<body>
    <form action="insert_books_process.php" method="post">
        ISBN: <input type="text" name="isbn" required /><br />
        Title: <input type="text" name="title" required /><br />
        Author: <input type="text" name="author" required /><br />
        Genre: <input type="text" name="genre" /><br />
        Available Copies: <input type="number" name="available_copies" /><br />
        Total Copies: <input type="number" name="total_copies" /><br />
        <input type="submit" value="Insert Book" />
    </form>
</body>

</html>