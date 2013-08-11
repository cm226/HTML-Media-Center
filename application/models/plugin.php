<?php
require_once("../scripts/JARVISCOMS/JARVIS.Comms.php");

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

function getPluginPage($plugin, $getmobileVersion = false)
{
	$comms = new JARVISCommas();
	if($getmobileVersion)
		$reply = $comms->requestMobilePluginPage($plugin);
	else
		$reply = $comms->requestPluginPage($plugin);
	
	return $reply;
}

function getPluginReply($pluginCallbackID, $contextArgs)
{
	$comms = new JARVISCommas();
	echo "callback ID:".$pluginCallbackID;
	$reply = $comms->requestPluginInteractionPage($pluginCallbackID, $contextArgs);
	
	return $reply;
}


}

?>
