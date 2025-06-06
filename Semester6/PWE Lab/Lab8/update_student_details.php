<?php
include 'db_config.php';

if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['student_id'])) {
    $student_id = $_POST['student_id'];
    $roll_number = $_POST['roll_number'];
    $name = $_POST['name'];
    $email = $_POST['email'];
    $address = $_POST['address'];
    $department = $_POST['department'];
    $room_allocated = $_POST['room_allocated'];
    $bill_paid = $_POST['bill_paid'];

    // Prepare SQL statement
    $sql = "UPDATE Students SET roll_number=?, name=?, email=?, address=?, department=?, room_allocated=?, bill_paid=? WHERE id=?";
    $stmt = $conn->prepare($sql);

    // Bind parameters
    $stmt->bind_param("sssssssi", $roll_number, $name, $email, $address, $department, $room_allocated, $bill_paid, $student_id);

    // Execute statement
    if ($stmt->execute()) {
        // Redirect back to edit_student.php with success message
        header("Location: edit_student.php?id=" . $student_id . "&success=true");
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