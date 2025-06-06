<?php
 $user = "root";
 $password = "";
 $db = "library_db";
 $server = "localhost";
 
 $link = mysqli_connect($server,$user,$password);
 if(!$link){
    die("Connection is not Established");
 }
 
 $seldb = mysqli_select_db($link,$db);
 if(!$seldb){
    die("Database is not selected");
 }
  ?>