<?php
require_once('Transever.php');
require_once('Messages/listPluginsMessage.php');
require_once('Messages/RequestPluginPageMessage.php');
require_once('Messages/PluginPageInteractionMessage.php');
require_once('Messages/RequestMobilePluginPageMessage.php');
require_once('Messages/RequestDiagnosticMessage.php');

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


function send($message)
{
	$this->transever->sendMessage($message);
	return $this->transever->readReply();
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

function requestMobilePluginPage($pluginName)
{
	$this->transever->sendMessage(new RequestMobilePluginPageMessage($pluginName));
	return $this->transever->readReply();
}


function requestPluginInteractionPage($pluginCallbackID, $pluginContextArgs)
{
	$this->transever->sendMessage(new PluginPageInteractionMessage($pluginCallbackID, $pluginContextArgs));
	return $this->transever->readReply();
}


}
