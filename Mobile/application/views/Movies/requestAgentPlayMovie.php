<?php
require (ROOT . DS . 'scripts' . DS . 'AgentComms' . DS . 'AgientComFunctions.php');

$return = playVideoStream($agentIP,"test");
echo "return from agent = ".$return;

?>
