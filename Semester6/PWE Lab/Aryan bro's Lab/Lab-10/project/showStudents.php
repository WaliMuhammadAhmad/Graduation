<?php
include_once 'db_config.php';

if (isset($_GET['delete_roll_number'])) {
    $deleteRollNumber = $_GET['delete_roll_number'];

    $deleteQuery = "DELETE FROM students WHERE RollNumber = '$deleteRollNumber'";
    
    $deleteResult = mysqli_query($link, $deleteQuery);

    if ($deleteResult) {
        echo "Student deleted successfully!";
    } else {
        echo "Error: " . mysqli_error($link);
    }
}

$query = "SELECT * FROM students";
$result = mysqli_query($link, $query);
?>

<!DOCTYPE html>
<html>

<head>
    <title>Student Data</title>
    <style>
    table,
    th,
    td {
        border: 1px solid black;
        border-collapse: collapse;
        padding: 5px;
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

    <h1>Student Data</h1>

    <!-- <button><a href="InsertStudent.php">Insert New Student</a></button> -->

    <table>
        <thead>
            <tr>
                <th>Roll Number</th>
                <th>Name</th>
                <th>Department</th>
                <th>Program</th>
                <th>Contact Information</th>
                <th>Update</th>
                <th>Delete</th>
            </tr>
        </thead>
        <tbody>
            <?php
            while ($row = $result->fetch_assoc()) {
                echo "<tr>";
                echo "<td>" . $row['RollNumber'] . "</td>";
                echo "<td>" . $row['Name'] . "</td>";
                echo "<td>" . $row['Department'] . "</td>";
                echo "<td>" . $row['Program'] . "</td>";
                echo "<td>" . $row['ContactInformation'] . "</td>";

                echo "<td><a href='UpdateStudent.php?roll_number=" . $row['RollNumber'] . "'>Update</a></td>";

                echo "<td><a href='#' onclick='confirmDelete(\"" . $row['RollNumber'] . "\");'>Delete</a></td>";

                echo "</tr>";
            }
            ?>
        </tbody>
    </table>

    <br>
    <a href="Home.php">Go back to Home</a>

    <script>
    function confirmDelete(rollNumber) {
        if (confirm("Are you sure you want to delete this student?")) {
            window.location.href = 'ShowStudents.php?delete_roll_number=' + rollNumber;
        }
    }
    </script>

</body>

</html>