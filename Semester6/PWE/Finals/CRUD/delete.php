<?php
include_once('connection.php');
$id=$_REQUEST['id'];

$q="delete from admin where id=".$id;
$bol=mysqli_query ($link,$q);
if ($bol)
header("Refresh:0; url=practice.php");

?>
