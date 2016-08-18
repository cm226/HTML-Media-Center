<?php
require_once('AbstractMessage.php');

class RequestNextChunkMessage extends AbstractMessage
{

	public function getMessage()
	{
		return "RnextChunk$";
	}
}