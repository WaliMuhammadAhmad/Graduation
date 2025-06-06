<?php
session_start();
?>
<!DOCTYPE html>
<html>
<body>

<?php
if(isset($_SESSION['name']))
{
    echo($_SESSION['name']);
   
}
else{
	 header('Location: index.php');
    exit();
}
?>
<br/><a href="destroy.php" >Sign Out</a>
</body>
</html>
