<?php
$filename='Files/1.txt';
$handle=fopen($filename,'r');
$some=fread($handle,15);
echo $some;
echo "</br>";
$whole=fread($handle,filesize($filename));
echo $whole;
?>
<?php
$filename='Files/2.txt';
$handle=fopen($filename,'w');
$bol=fwrite($handle,'ABCDE');
?>
<?php
$filename='Files/3.txt';
$handle=fopen($filename,'a');
$bol=is_writable($filename);
if($bol){
fwrite($handle,'ABCDE');
}
?>
<?php
$delete=unlink('Files/4.txt');
if($delete)
{echo "the File Have been deleted";}

rmdir('hellow');//to delete directory
mkdir('hellow');//to make directory


?>
