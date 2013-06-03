<?php
require_once("../../Desktop/scripts/JARVISCOMS/JARVIS.Comms.php");

class Plugin extends Model {


function getPluginList()
{
	$comms = new JARVISCommas();
	$reply = $comms->listLoadedPlugins();
	
	$pluginCatagories = explode('%',$reply);
	array_shift($pluginCatagories); // remove the empty value
	$plugins = array();
	
	foreach($pluginCatagories as $pluginCat)
	{
		$pluginCatagorieList = explode(',',$pluginCat);
		array_push($plugins,$pluginCatagorieList);
	}
	
	return $plugins;
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
