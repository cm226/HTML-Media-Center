<?php
require_once('AbstractMessage.php');

class AgentRequestMessage extends AbstractMessage
{	
	function __construct()
	{
	}

	public function getMessage()
	{
		return "APR$";
	}
}

?>
