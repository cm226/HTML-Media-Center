<?php	

define('DS', DIRECTORY_SEPARATOR);
define('ROOT', dirname(dirname(__FILE__)));

if (strtoupper(substr(PHP_OS, 0, 3)) === 'WIN') {
    define('SPACE_CHAR', '%20');
} else {
    define('SPACE_CHAR', ' ');
}

if(isset($_GET['url']))
	$url = $_GET['url'];
else
{
	header('Location: ../Mobile/Start/Home');
}

require_once (ROOT . DS . 'library' . DS . 'bootstrap.php');
