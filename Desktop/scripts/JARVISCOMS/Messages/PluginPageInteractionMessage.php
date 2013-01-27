<?php

require_once('AbstractMessage.php');

class PluginPageInteractionMessage extends AbstractMessage
{
	var $contextInfo;
	
	function __construct($callbackID ,$contextArr)
	{
		$this->contextInfo = array_reduce($contextArr,"reduceStrArr");
	}
	
	function reduceStrArr($v, $w)
	{
		$v .= "$".$w;
		return $v;
	}
	
	public function getMessage()
	{
		return "pcb$".$contextInfo;
	}
}