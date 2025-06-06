<?php
session_start();
?>
<?php
include_once('connection.php');
if(isset($_POST['myname']) && isset($_POST['mypassword'])){
	$myname = $_POST['myname'];
	$mypassword = $_POST['mypassword'];
	
$q = "select * from student where name='".$myname."' AND password='".$mypassword."' limit 1";
$query = mysqli_query($link,$q);


if(mysqli_num_rows($query)==1 )
{
	$_SESSION['name'] = $myname;
	header('Location: 2nd.php');
	 exit();
}
else{
	
	echo ("Error");
}
}
?>

<html>
<head>
</head>
<body>
<form method="post" action="">
Name:
<input type="text" id="myname" name="myname"/><br/>
password:
<input type="text" id="mypassword" name="mypassword"/><br/>
<input type="submit" value="Sign-In" />
</form>

</body>

</html>