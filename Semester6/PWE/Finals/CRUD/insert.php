<?php
include_once('connection.php');
if(isset($_POST['myname']) && isset($_POST['mypassword'])){
	$name = $_POST["myname"];
	$password = $_POST["mypassword"];
	if($name !== "" && $password !== ""){
	$q="insert into admin (username,password) values ('$name', '$password')";
	$bool=mysqli_query($link,$q);			

	if ($bool){
	echo "Records Have been Entered";}
	}
	else{
		echo("form is empty");
	}
}
?>

<html>
<head>
	<link rel="stylesheet" href="css/bootstrap.min.css">
	<link rel="stylesheet" href="css/mystyle.css">
	<script src="js/jquery-3.1.1.min.js"></script>
	<script src="js/bootstrap.min.js"></script>
</head>
<body class="container">
	<br/><br/><br/><br/>
	<form method="post">
		<label>Name:</label>
		<input type="text" name="myname" id="myname" placeholder="Enter Your Name" class="form-control"/>
		<br/>
		<label>password:</label>
		<input type="password" name="mypassword" id="mypassword" placeholder="Enter Your Password" class="form-control"/>
		<br/>
		<button class="btn btn-primary">Insert Value</button>
	</form>
</body>
</html>