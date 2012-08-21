<?php
require (ROOT . DS . 'scripts' . DS . 'AgentComms' . DS . 'AgientComFunctions.php');


//exec("cvlc -vvv ".$movie[0]['Movie']['movieURL']." --sout'#standard{access=http,mux=ts,dest=".$_SERVER['SERVER_ADDR'].":8080/current}'");
echo "cvlc -vvv ".$movie[0]['Movie']['movieURL']." --sout'#standard{access=http,mux=ts,dest=".$_SERVER['SERVER_ADDR'].":8080/current}'";

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
