<?php
session_start();
include 'db_config.php';

if (!isset($_SESSION['username'])) {
    header("Location: login.php");
}

$username = $_SESSION['username'];

// Display student data
$sql_paid = "SELECT * FROM Students WHERE bill_paid='Yes'";
$result_paid = $conn->query($sql_paid);

$sql_unpaid = "SELECT * FROM Students WHERE bill_paid='No'";
$result_unpaid = $conn->query($sql_unpaid);
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <title>Hostel Management System</title>
    <link href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css" rel="stylesheet">
</head>

<body>
    <nav class="navbar navbar-expand-lg navbar-light bg-light">
        <a class="navbar-brand" href="#">Welcome,
            <?php echo $username; ?>
        </a>
        <ul class="navbar-nav ml-auto">
            <li class="nav-item">
                <a class="nav-link" href="logout.php">Sign Out</a>
            </li>
        </ul>
    </nav>

    <!-- Remaining part of Home.php -->

    <!-- Remaining part of Home.php -->

    <div class="container mt-5">
        <h2>Students who have paid their mess bill</h2>
        <table class="table">
            <thead>
                <tr>
                    <th>Roll Number</th>
                    <th>Name</th>
                    <th>Email</th>
                    <th>Address</th>
                    <th>Department</th>
                    <th>Room Allocated</th>
                    <th>Bill Paid</th>
                    <th>Action</th>
                </tr>
            </thead>
            <tbody>
                <?php
                if ($result_paid->num_rows > 0) {
                    while ($row = $result_paid->fetch_assoc()) {
                        echo "<tr>";
                        echo "<td>" . $row['roll_number'] . "</td>";
                        echo "<td>" . $row['name'] . "</td>";
                        echo "<td>" . $row['email'] . "</td>";
                        echo "<td>" . $row['address'] . "</td>";
                        echo "<td>" . $row['department'] . "</td>";
                        echo "<td>" . $row['room_allocated'] . "</td>";
                        echo "<td>" . $row['bill_paid'] . "</td>";
                        echo "<td>
                            <a href='edit_student.php?id=" . $row['id'] . "' class='btn btn-sm btn-primary'>Edit</a>
                          </td>";
                        echo "<td><form method='post' action='update_student.php'>
                            <input type='hidden' name='student_id' value='" . $row['id'] . "'>
                            <input type='hidden' name='bill_paid' value='No'>
                            <button type='submit' class='btn btn-sm btn-danger'>Mark Unpaid</button>
                          </form></td>";
                        echo "</tr>";
                    }
                } else {
                    echo "<tr><td colspan='7'>No students have paid their mess bill.</td></tr>";
                }
                ?>
            </tbody>
        </table>

        <h2>Students who have not paid their mess bill</h2>
        <table class="table">
            <thead>
                <tr>
                    <th>Roll Number</th>
                    <th>Name</th>
                    <th>Email</th>
                    <th>Address</th>
                    <th>Department</th>
                    <th>Room Allocated</th>
                    <th>Bill Paid</th>
                    <th>Action</th>
                </tr>
            </thead>
            <tbody>
                <?php
                if ($result_unpaid->num_rows > 0) {
                    while ($row = $result_unpaid->fetch_assoc()) {
                        echo "<tr>";
                        echo "<td>" . $row['roll_number'] . "</td>";
                        echo "<td>" . $row['name'] . "</td>";
                        echo "<td>" . $row['email'] . "</td>";
                        echo "<td>" . $row['address'] . "</td>";
                        echo "<td>" . $row['department'] . "</td>";
                        echo "<td>" . $row['room_allocated'] . "</td>";
                        echo "<td>" . $row['bill_paid'] . "</td>";
                        echo "<td>
                            <a href='edit_student.php?id=" . $row['id'] . "' class='btn btn-sm btn-primary'>Edit</a>
                          </td>";
                        echo "<td><form method='post' action='update_student.php'>
                            <input type='hidden' name='student_id' value='" . $row['id'] . "'>
                            <input type='hidden' name='bill_paid' value='Yes'>
                            <button type='submit' class='btn btn-sm btn-success'>Mark Paid</button>
                          </form></td>";
                        echo "</tr>";
                    }
                } else {
                    echo "<tr><td colspan='7'>No students have not paid their mess bill.</td></tr>";
                }
                ?>
            </tbody>
        </table>
    </div>


</body>

</html>