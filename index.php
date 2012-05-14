<?php
$useragent=$_SERVER['HTTP_USER_AGENT'];

if(strlen(strstr($useragent, 'Android', true)) > 0)
	header('Location: Mobile/');
else
	header('Location: Desktop/');

?>
