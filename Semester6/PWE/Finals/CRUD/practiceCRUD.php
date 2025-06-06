<?php
include_once('connection.php');

// Insert operation
if(isset($_POST['myname']) && isset($_POST['mypassword'])){
	$name = $_POST["myname"];
	$password = $_POST["mypassword"];
	if($name !== "" && $password !== ""){
		$q="insert into admin (username,password) values ('$name', '$password')";
		$bool=mysqli_query($link,$q);			

		if ($bool){
			echo "Records have been entered";
		}
	}
	else{
		echo("Form is empty");
	}
}

// Read operation
$s = "select * from admin";
$rs = mysqli_query($link,$s);

// Delete operation
if(isset($_GET['id'])){
	$id=$_GET['id'];
	$q="delete from admin where id=".$id;
	$bool=mysqli_query($link,$q);
	if ($bool){
		header("Location: practice.php"); // Redirect back to the same file after deletion
		exit();
	}
}
// Update operation
if(isset($_GET['idd'])){
    $idd=$_GET['idd'];

    $q="select username, password from admin where id=".$idd;
    $rs=mysqli_query ($link,$q); 
    mysqli_error($link);
    $row=mysqli_fetch_array($rs);
    $name=$row['username'];
    $password=$row['password'];

    if(isset($_GET['name']) && isset($_GET['password'])){
        $name=$_GET['name'];
        $password=$_GET['password'];

        if($name !== "" && $password !== ""){
            $q="update admin set username='".$name."', password='".$password."' where id=".$idd;
            $bol=mysqli_query($link,$q);
            if ($bol) {
                header("Location: practice.php"); // Redirect back to the same file after update
                exit();
            }
        } else {
            echo("Form is empty");
        }
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
		<label>Password:</label>
		<input type="password" name="mypassword" id="mypassword" placeholder="Enter Your Password" class="form-control"/>
		<br/>
		<button class="btn btn-primary">Insert Value</button>
	</form>
	<h1>Admin</h1>
    <table border="2px" width="350px" height="200px" align="center">
		<tr>
			<td>ID</td>
			<td>NAME</td>
			<td>PASSWORD</td>
			<td>DELETE</td>
			<td>EDIT</td>
		</tr>
		<?php
		while ($rows=mysqli_fetch_array($rs))
		{ 
			$id=$rows['id'];
			$name=$rows['username'];
            $password=$rows['password'];
		?>
		<tr>
			<td><?php echo $id; ?></td>
			<td><?php echo $name; ?></td>
			<td><?php echo $password; ?></td>
			<td><a href="practice.php?id=<?php echo $id?>">DEL</a></td>
			<td><a href="practice.php?idd=<?php echo $id?>">EDIT</a></td>
		</tr>
		<?php
		}
		?>
	</table>
	<form action="practice.php" method="GET">
    Name: <input type="text" name="name" id="name" value="<?php echo $name?>" /><br/>
    Password: <input type="password" name="password" id="password" value="<?php echo $password?>" /><br/>
    <input type="submit" name="submit" value="Update!" />
    <input type="hidden" value="<?php echo $idd?>" name="idd" id="idd" /> 
</form>

</body>
</html>