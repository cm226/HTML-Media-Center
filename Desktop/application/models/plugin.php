<?php
require_once("../../Desktop/scripts/JARVISCOMS/JARVIS.Comms.php");

class Plugin extends Model {


function getPluginList()
{
	$comms = new JARVISCommas();
	$reply = $comms->listLoadedPlugins();
	
	return explode(",",$reply);
}

function getPluginPage($plugin)
{
	$comms = new JARVISCommas();
	$reply = $comms->requestPluginPage($plugin);
	
	return $reply;
}

function getPluginReply($pluginCallbackID, $contextArgs)
{
	$comms = new JARVISCommas();
	$reply = $comms->requestPluginInteractionPage($pluginCallbackID, $contextArgs);
	
	return $reply;
}

function notifyPluginOfUpload($pluginCallbackID,$contextArgs)
{
	$comms = new JARVISCommas();
	$reply = $comms->requestPluginInteractionPage($pluginCallbackID, $contextArgs);
	
	return $reply;
}


}

?>
