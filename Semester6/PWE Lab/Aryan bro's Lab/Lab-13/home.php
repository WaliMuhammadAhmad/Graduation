<?php
session_start();
include('db_config.php');

if (!isset($_SESSION["admin_username"])) {
    header("Location: login.php");
    exit();
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Check if all fields are filled
    if (isset($_POST['name']) && isset($_POST['price']) && isset($_FILES['image'])) {
        // Get form data
        $name = $_POST['name'];
        $price = $_POST['price'];
        
        // Handle image upload
        $targetDir = "uploads/";
        $targetFile = $targetDir . basename($_FILES["image"]["name"]);
        $uploadOk = 1;
        $imageFileType = strtolower(pathinfo($targetFile,PATHINFO_EXTENSION));
        
        // Check if file already exists
        if (file_exists($targetFile)) {
            echo "file already exists.";
            $uploadOk = 0;
        }
        
        // Check file size
        if ($_FILES["image"]["size"] > 500000) {
            echo "Sorry, your file is too large.";
            $uploadOk = 0;
        }
        
        // Allow certain file formats
        if($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg"
        && $imageFileType != "gif" ) {
            echo "Sorry, only JPG, JPEG, PNG & GIF files are allowed.";
            $uploadOk = 0;
        }
        
        if ($uploadOk == 0) {
            echo "Sorry, your file was not uploaded.";

        } else {
            if (move_uploaded_file($_FILES["image"]["tmp_name"], $targetFile)) {
                // File uploaded successfully, now insert data into database
                $insert_query = "INSERT INTO Orders (name, price, image, status) VALUES ('$name', '$price', '$targetFile', 'New')";
                if (mysqli_query($link, $insert_query)) {
                    echo "New product added successfully.";
                } else {
                    echo "Error: " . $insert_query . "<br>" . mysqli_error($link);
                }
            } else {
                echo "Faild to add image.";
            }
        }
    } else {
        echo "Please fill all fields.";
    }
}

if (isset($_GET["action"]) && $_GET["action"] == "logout") {
    session_destroy();
    header("Location: login.php");
    exit();
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin Dashboard</title>
    <style>
    body {
        font-family: Arial, sans-serif;
        margin: 0;
        padding: 0;
    }

    header {
        background-color: green;
        color: white;
        text-align: center;
        display: flex;
        justify-content: center;
        align-items: center;
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

    .sign-out-dropdown {
        position: relative;
        display: inline-block;
        cursor: pointer;
    }

    .dropdown-content {
        display: none;
        position: absolute;
        background-color: #f9f9f9;
        min-width: 160px;
        box-shadow: 0 8px 16px 0 rgba(0, 0, 0, 0.2);
        z-index: 1;
    }

    .dropdown-content a {
        color: black;
        padding: 12px 16px;
        text-decoration: none;
        display: block;
        cursor: pointer;
    }

    .dropdown-content a:hover {
        background-color: #ddd;
    }

    .sign-out-dropdown:hover .dropdown-content {
        display: block;
    }

    form {
        width: 20%;
        display: flex;
        flex-direction:column;
        text-align: center;
        justify-self: center;
        margin: 20px;
        gap: 10px;
    }

    section {
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
    }

    input[type="text"],
    input[type="number"],
    input[type="file"] {
        margin-right: 10px;
        padding: 8px;
        
    }

    input[type="submit"] {
        padding: 8px 15px;
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
    .btn {
        padding: 8px 15px;
        background-color: green;
        color: white;
        border: none;
        border-radius: 5px;
        width: 100%;
        cursor: pointer;
    }
    </style>
</head>

<body>
    <header>
        <div class="user-info">
            <h2><span>Shawls</span></h2>
            <div class='nav'>
                <a href="?action=home">Add Products</a>
                <a href="products.php">View Products</a>
                <a href="?action=logout">Logout</a>
            </div>
        </div>
    </header>

    <section>
    <h2>Add New Product</h2>
    <form id="productForm" method="post" enctype="multipart/form-data">
        <input type="text" id="productName" name="name" placeholder="Product Name" required>
        <input type="number" id="productPrice" name="price" placeholder="Price" step="0.01" required>
        <input type="file" name="image" accept="image/*" required>
        <input class="btn" type="submit" value="Add Product">
    </form>
</section>
<script>
    document.getElementById("productForm").addEventListener("submit", function(event) {
        
        var productName = document.getElementById("productName").value;
        var productPrice = document.getElementById("productPrice").value;
        if (!productName || !/^[a-zA-Z]+$/.test(productName)) {
            alert("Please enter a valid product name");
            event.preventDefault(); // Prevent form submission
            return;
        }

        if (isNaN(productPrice) || productPrice <= 0) {
            alert("Please enter a valid price.");
            event.preventDefault(); // Prevent form submission
            return;
        }
    });
    var confirmationMessage = "<?php echo isset($_COOKIE['confirmation_message']) ? $_COOKIE['confirmation_message'] : '' ?>";
    if (confirmationMessage) {
        setTimeout(function() {
            alert(confirmationMessage);
        }, 60); // 60000 milliseconds = 1 minute
    }
</script>
</body>

</html>