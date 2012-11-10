<?php
require_once('AbstractMessage.php');

class RequestPluginPageMessage extends AbstractMessage
{
	var $pluginName;
	
	function __construct($name)
	{
		
		$this->$pluginName = $name;
		
	}

	public function getMessage()
	{
		return "pPageReq$".$this->$pluginName;
	}
}

?>