<?php
include 'connection.php';
$id=$_REQUEST['id'];

$q="select username from admin where id=".$id;
$rs=mysqli_query ($link,$q); 
mysqli_error($link);
$row=mysqli_fetch_array($rs);
$name=$row[0];

if(isset($_GET['name'])){
$name=$_GET['name'];
$id=$_GET['id'];

if($name !== ""){
$q="update admin set username='".$name."' where id=".$id;
$bol=mysqli_query($link,$q);
if ($bol)
{header("Refresh:0; url=practice.php");}
}
else{
	echo("form is empty");
}
}
?>
<form action="">
name:<input type="text" name="name" id="name" value="<?php echo $name?>" />
<input type="submit" name="submit" value="Update!" />
<input type="hidden" value="<?php echo $id?>" name="id" id="id" /> 
</form>
