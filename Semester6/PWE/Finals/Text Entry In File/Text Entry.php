<?php
$textarea=$_GET['textarea'];
if($textarea == "")
{
	echo "Form is Empty";
}
else
{
$filename='Files/1.txt';
$handle=fopen($filename,'w');
$bol=is_writable($filename);
if($bol){ 
fwrite($handle,$textarea);
echo "Data Have Been Inserted";

}
}
?>
