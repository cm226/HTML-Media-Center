<?php
require_once('AbstractMessage.php');

class RequestStreamMediaMessage extends AbstractMessage
{
	var $songIDArray;
	
	function __construct($songIDArray)
	{
		$this->songIDArray = $songIDArray;	
	}

	public function getMessage()
	{
		$songElements = implode('$',$this->songIDArray);
		return "RMS$".$songElements;
	}
}

?>
