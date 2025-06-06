<?php
include_once('connection.php');

$s = "select * from student";
$rs = mysqli_query($link,$s);
?>

<html>
<head>
<link rel="stylesheet" href="css/bootstrap.min.css">
<link rel="stylesheet" href="css/mystyle.css">
<script src="js/jquery-3.1.1.min.js"></script>
<script src="js/bootstrap.min.js"></script>
</head>
<body class="container">
<table class="table table-hover">
<tr>
<th>ID</th>
<th>Name</th>
<th>Password</th>
</tr>
<?php

while ($rows=mysqli_fetch_assoc($rs))
{
?>	
	<tr>
	<td><?php echo $rows['id']; ?> </td>
	<td><?php echo $rows['name']; ?> </td>
	<td><?php echo $rows['password']; ?> </td>
	</tr>
	<?php
}
?>
</table>
</body>
</html>