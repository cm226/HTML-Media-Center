<?php
require_once('AbstractMessage.php');

class LSPlugins extends AbstractMessage
{

	public function getMessage()
	{
		return "ppoll$";
	}
}