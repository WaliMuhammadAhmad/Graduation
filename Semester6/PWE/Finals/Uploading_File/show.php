 <?php
include 'connect.php';
$s = "select * from info";
$rs = mysqli_query($link,$s);

$rows=mysqli_fetch_assoc($rs);


?>
<html>
<body>
<?php

while ($rows=mysqli_fetch_assoc($rs))
{
?>	
    <br>
	<img src="pic/<?php echo $rows['pic_name']; ?>" width="10%" height="10%"/>
    <?php
    echo $rows['pic_name'];
    ?>
	<?php
}
?>

</body>
</html>