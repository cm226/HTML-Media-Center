<?php
require (ROOT . DS . 'scripts' . DS . 'AgentComms' . DS . 'AgientComFunctions.php');
	
	pauseVideoStream('192.168.0.198','current');

	exec('python '.ROOT . DS . 'scripts' . DS .'vlcTelnetInterface.py -pause current');
	echo "pause";
?>