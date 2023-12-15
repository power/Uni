<?php

/*
	Desc: Example connection string
	
	Author: Lynsay A. Shepherd
	
	Date: November 2020
	
*/

//connection details
$servername = "";
$dbusername = "sqlXXXXXXX";
$dbpassword = "password_here";
$dbname = "sqlXXXXXXX";


$conn = mysqli_connect($servername, $dbusername, $dbpassword, $dbname);

mysqli_close($conn);

?>