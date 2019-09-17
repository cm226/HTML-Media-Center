<?php
require_once('AbstractMessage.php');

class RequestMobilePluginPageMessage extends AbstractMessage
{
	var $pluginName;
	
	function __construct($name)
	{
		
		$this->pluginName = $name;
		
	}

	public function getMessage()
	{
		return "rmpp$".$this->pluginName;
	}
}

?>
