<?php
include 'config.php';
include 'functions.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST['username'];
    $password = $_POST['password'];

    $sql = "SELECT * FROM Admin WHERE username = '$username' AND password = '$password'";
    $result = mysqli_query($link, $sql);

    if ($result->num_rows == 1) {
        $_SESSION['admin_username'] = $username;
        header("Location: home.php");
    } else {
        $error = "Invalid username or password.";
    }
}
?>

<!-- HTML form for admin login -->
<!DOCTYPE html>
<html>

<head>
    <title>Login</title>
    <link rel="stylesheet" href="style.css">

</head>

<body>
    <h2>Login</h2>
    <?php if (isset($error)) echo "<p>$error</p>"; ?>
    <form method="post" action="">
        Username: <input type="text" name="username" required><br>
        Password: <input type="password" name="password" required><br>
        <input type="submit" value="Login">
    </form>
</body>

</html>