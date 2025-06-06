<?php
include 'connect.php';

$s = "select id,name from admin";
$rs = mysqli_query($link,$s);
?>

<table border="2px" width="350px" height="200px" align="center">
<tr><td>ID</td>
<td>NAME</td>
<td>DELETE</td>
<td>EDIT</td>
</tr>
<?php
while ($rows=mysqli_fetch_array($rs))
{ $id=$rows['id'];
$name=$rows['name'];
?>
<tr><td><?php echo $id; ?></td>
<td><?php echo $name; ?></td>
<td><a href="delete.php? id=<?php echo $id?>" />DEL</a></td>
<td><a href="update.php? id=<?php echo $id?>" />EDIT</a></td>
</tr>
<?php
}
?>
</table>
