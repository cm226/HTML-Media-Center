<?php
require (ROOT . DS . 'scripts' . DS . 'AgentComms' . DS . 'AgientComFunctions.php');
	stopVideoStream('192.168.0.198','current');
	
	exec('python '.ROOT . DS . 'scripts' . DS .'vlcTelnetInterface.py -stop current');
	echo "Stop";
?>