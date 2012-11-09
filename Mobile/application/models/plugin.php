<?php
require_once("..\..\Desktop\scripts\JARVISCOMS\JARVIS.Comms.php");

class Plugin extends Model {


function getPluginList()
{
	$comms = new JARVISCommas();
	$reply = $comms->listLoadedPlugins();
	
	return explode(",",$reply);
	
}


}

?>