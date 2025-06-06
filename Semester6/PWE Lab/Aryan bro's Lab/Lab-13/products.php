<?php
session_start();
include('db_config.php');

if (!isset($_SESSION["admin_username"])) {
    header("Location: login.php");
    exit();
}

// Fetch products from the database
$query = "SELECT * FROM Orders";
$result = mysqli_query($link, $query);

if (!$result) {
    echo "Error: " . $query . "<br>" . mysqli_error($link);
    exit();
}
?>

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin Dashboard</title>
    <style>
    body {
        font-family: Arial, sans-serif;
        margin: 0;
        padding: 0;
        background-color: #f4f4f4;
    }

    header {
        background-color: green;
        color: white;
        text-align: center;
        display: flex;
        justify-content: center;
        align-items: center;
    }

    .container {
        display: flex;
        flex-wrap: wrap;
        justify-content: center;
        gap: 20px;
        padding: 20px;
    }

    .card {
        background-color: #fff;
        box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        border-radius: 5px;
        width: 250px;
        padding: 20px;
        text-align: center;
    }

    .card img {
        width: 100%;
        border-radius: 5px;
        margin-bottom: 10px;
    }

    .card h3 {
        margin-bottom: 10px;
    }

    .card p {
        margin-bottom: 10px;
    }

    .user-info {
        width: 80%;
        display: flex;
        align-items: center;
        justify-content: space-between;
    }

    .user-info span {
        margin-right: 10px;
    }

    h1 {
        text-align:center;
    }

    .btn {
        padding: 8px 15px;
        background-color: green;
        color: white;
        border: none;
        border-radius: 5px;
        width: 100%;
        cursor: pointer;
    }
    .nav {
        display: flex;
        justify-content: center;
        gap: 20px;
        color: white;
    }
    a {
        color: white;
        text-decoration: none;
    }
    </style>
</head>

<body>
<header>
        <div class="user-info">
            <h2><span>Shawls</span></h2>
            <div class='nav'>
                <a href="home.php">Add Products</a>
                <a href="products.php">View Products</a>
                <a href="?action=logout">Logout</a>
            </div>
        </div>
    </header>

    <h1>Latest Products</h1>
    <div class="container">
        <?php
        while ($row = mysqli_fetch_assoc($result)) {
        ?>
        <div class="card">
            <img src="<?php echo $row['image']; ?>" alt="Product Image">
            <h3><?php echo $row['name']; ?></h3>
            <p>$<?php echo $row['price']; ?>/-</p>
            <button class="btn">Add to Cart</button>
        </div>
        <?php
        }
        ?>
    </div>
</body>

</html>