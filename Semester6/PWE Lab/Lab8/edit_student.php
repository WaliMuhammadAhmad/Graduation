<?php
include 'db_config.php';

if ($_SERVER["REQUEST_METHOD"] == "GET" && isset($_GET['id'])) {
    $student_id = $_GET['id'];

    // Fetch student details
    $sql = "SELECT * FROM Students WHERE id=?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("i", $student_id);
    $stmt->execute();
    $result = $stmt->get_result();

    if ($result->num_rows == 1) {
        $row = $result->fetch_assoc();
        $roll_number = $row['roll_number'];
        $name = $row['name'];
        $email = $row['email'];
        $address = $row['address'];
        $department = $row['department'];
        $room_allocated = $row['room_allocated'];
        $bill_paid = $row['bill_paid'];
    } else {
        echo "Student not found.";
        exit();
    }

    // Close statement
    $stmt->close();
} else {
    echo "Invalid request.";
    exit();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Edit Student Details</title>
    <link href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
    <div class="container mt-5">
        <h2>Edit Student Details</h2>
        <form method="post" action="update_student_details.php">
            <input type="hidden" name="student_id" value="<?php echo $student_id; ?>">
            <div class="form-group">
                <label for="roll_number">Roll Number:</label>
                <input type="text" class="form-control" id="roll_number" name="roll_number" value="<?php echo $roll_number; ?>" required>
            </div>
            <div class="form-group">
                <label for="name">Name:</label>
                <input type="text" class="form-control" id="name" name="name" value="<?php echo $name; ?>" required>
            </div>
            <div class="form-group">
                <label for="email">Email:</label>
                <input type="email" class="form-control" id="email" name="email" value="<?php echo $email; ?>" required>
            </div>
            <div class="form-group">
                <label for="address">Address:</label>
                <textarea class="form-control" id="address" name="address" rows="3" required><?php echo $address; ?></textarea>
            </div>
            <div class="form-group">
                <label for="department">Department:</label>
                <input type="text" class="form-control" id="department" name="department" value="<?php echo $department; ?>" required>
            </div>
            <div class="form-group">
                <label for="room_allocated">Room Allocated:</label>
                <input type="text" class="form-control" id="room_allocated" name="room_allocated" value="<?php echo $room_allocated; ?>" required>
            </div>
            <div class="form-group">
                <label for="bill_paid">Bill Paid:</label>
                <select class="form-control" id="bill_paid" name="bill_paid" required>
                    <option value="Yes" <?php if ($bill_paid == 'Yes') echo 'selected'; ?>>Yes</option>
                    <option value="No" <?php if ($bill_paid == 'No') echo 'selected'; ?>>No</option>
                </select>
            </div>
            <button type="submit" class="btn btn-primary">Update</button>
        </form>
    </div>
</body>
</html>
