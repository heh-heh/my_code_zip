<?
	// inc/db.inc.php

	$DBHost = "localhost";
	$DBUser = "robot";
	$DBPass = "robot";
	$DBName = "robot";
	$DBChar = "utf8"; // utf8

	$conn = mysql_connect($DBHost, $DBUser, $DBPass);
	$selectResult = mysql_select_db($DBName, $conn) or die("DB 선택 에러");
	mysql_query("set names $DBChar");

	$user_neme = "user_name";
?>

