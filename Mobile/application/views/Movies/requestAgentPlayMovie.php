<?php
require (ROOT . DS . 'scripts' . DS . 'AgentComms' . DS . 'AgientComFunctions.php');
require (ROOT . DS . 'scripts' . DS . 'telnet.php');

exec("pgrep vlc", $output, $return);
if ($return == 1) {
    echo exec("vlc --ttl 1 -vvv --intf telnet --telnet-port 4212 --telnet-password mediaPWLOL 2>&1");
	
}

//exec('bash -c "exec nohup setsid vlc -vvv '.$movie[0]['Movie']['movieURL'].' --sout \'#standard{access=http,mux=ts,dst='.$_SERVER['SERVER_ADDR'].':8080/current}\' > /dev/null 2>&1 &"');

openSocket("localhost");
telnet_vlc_addmedia("current", $movie[0]['Movie']['movieURL'],"mediaPWLOL", $_SERVER['SERVER_ADDR']);

$return = playVideoStream($agentIP,"http://".$_SERVER['SERVER_ADDR'].":8080/current");

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
