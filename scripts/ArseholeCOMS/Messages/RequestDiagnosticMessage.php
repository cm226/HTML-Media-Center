<?php
require_once('AbstractMessage.php');

class RequestDiagnosticMessage extends AbstractMessage
{	
	function __construct()
	{
	}

	public function getMessage()
	{
		return "RDiag$";
	}
}

?>
