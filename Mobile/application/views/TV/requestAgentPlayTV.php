<?php
require (ROOT . DS . 'scripts' . DS . 'AgentComms' . DS . 'AgientComFunctions.php');

#exec("pgrep vlc", $output, $return);
#if ($return == 1) {
   # exec("vlc --ttl 1 -vvv --intf telnet --telnet-port 4212 --telnet-password mediaPWLOL 2>&1");
	
#}

#exec('python '.ROOT . DS . 'scripts' . DS .'vlcTelnetInterface.py -add current \''.$tv[0]['Episode']['filePath'].'\'');
#$return = playVideoStream($agentIP,"http://".$_SERVER['SERVER_ADDR'].":8080/current");
$return = 1;
if($return >0)
{
	?>
		<div style="Background-Color = green;"> all is well with the worldd </div>
	<?php
}
else
{
	?>
		<div style="Background-Color = red;"> times have been better (error from coms reciver) </div>
	<?php
}

?>
