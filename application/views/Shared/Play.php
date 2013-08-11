<?php
require (ROOT . DS . 'scripts' . DS . 'AgentComms' . DS . 'AgientComFunctions.php');
	playVideoStream('192.168.0.198','current');
	
	exec('python '.ROOT . DS . 'scripts' . DS .'vlcTelnetInterface.py -play current');
		
	echo "Playing";
?>