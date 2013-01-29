<?php

require_once('AbstractMessage.php');

function reduceStrArr($v, $w)
{
	$v .= "$".$w;
	return $v;
}
	
class PluginPageInteractionMessage extends AbstractMessage
{
	var $contextInfo;
	var $callbackID;
	

	
	function __construct($callbackID ,$contextArr)
	{
		$this->callbackID = $callbackID;
		$this->contextInfo = array_reduce($contextArr,"reduceStrArr");
	}

	public function getMessage()
	{
		return "pcb$".$this->callbackID.$this->contextInfo;
	}
}