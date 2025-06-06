<?php
$user = "root";
$password = "";
$db = "mydatabase";
$server = "localhost";

$link = mysqli_connect($server, $user, $password);
if(!$link){
	die("Could not connect to sql server");
}
if(!mysqli_select_db($link,$db)){
	die("could not open DB");
}

?>