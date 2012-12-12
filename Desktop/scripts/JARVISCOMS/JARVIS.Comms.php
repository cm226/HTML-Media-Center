<?php
require_once('Transever.php');
require_once('Messages/listPluginsMessage.php');
require_once('Messages/RequestPluginPageMessage.php');

class JARVISCommas
{
var $transever;

function __construct()
{
       $this->transever = new Transever();
	   if(!$this->transever->isConnected())
	   {
	   		echo "Error Connecting to JARVIS, he isent there";
	   }
}

function listLoadedPlugins()
{
	$this->transever->sendMessage(new LSPlugins());
	return $this->transever->readReply();
}

function requestPluginPage($pluginName)
{
	$this->transever->sendMessage(new RequestPluginPageMessage($pluginName));
	return $this->transever->readReply();
}

}
