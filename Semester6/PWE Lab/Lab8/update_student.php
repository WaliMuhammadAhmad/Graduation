<?php
include 'db_config.php';

if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['student_id']) && isset($_POST['bill_paid'])) {
    $student_id = $_POST['student_id'];
    $bill_paid = $_POST['bill_paid'];

    // Prepare SQL statement
    $sql = "UPDATE Students SET bill_paid=? WHERE id=?";
    $stmt = $conn->prepare($sql);

    // Bind parameters
    $stmt->bind_param("si", $bill_paid, $student_id);

    // Execute statement
    if ($stmt->execute()) {
        // Redirect back to Home.php after successful update
        header("Location: Home.php");
        exit();
    } else {
        echo "Error updating record: " . $conn->error;
    }

    // Close statement
    $stmt->close();
} else {
    echo "Invalid request.";
}
?>
