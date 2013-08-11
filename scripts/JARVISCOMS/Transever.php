<?php

require_once("Messages/RequestNextChunkMessage.php");

class Transever
{

var $address = '127.0.0.1';
var $sock;
var $connected = false;

function __construct($port = 45001) 
{
	error_reporting(E_ALL);
	/* Allow the script to hang around waiting for connections. */
	set_time_limit(0);
	/* Turn on implicit output flushing so we see what we're getting
	 * as it comes in. */
	ob_implicit_flush();

	if (($this->sock = socket_create(AF_INET, SOCK_STREAM, SOL_TCP)) === false)
	{
		//echo "socket_create() failed: reason: " . socket_strerror(socket_last_error()) . "\n";
		return false;
	}
	
	if (socket_connect($this->sock, $this->address, $port) == false) 
	{
		//echo "socket_listen() failed: reason: " . socket_strerror(socket_last_error($this->sock)) . "\n";
		return false;
	}
	
	$timeout = array('sec'=>10,'usec'=>0);
  	socket_set_option($this->sock,SOL_SOCKET,SO_RCVTIMEO,$timeout);
  
	$this->connected = true;
	return true;
}

function __destruct()
{
	if($this->sock)
	{
		socket_close($this->sock);
	}
}

function isConnected()
{
	return $this->connected;	
}

public function sendMessage($Message)
{
	if($this->connected)
	{
		$messageStr = $Message->getMessage();
		$msgLen = strlen($messageStr);
		$lowBit = $msgLen & 255;
		$hightBit = $msgLen >> 8;
		
		$msgHeaderStr = chr($hightBit). chr($lowBit);
		$messageStr = $msgHeaderStr.$messageStr;
		
		socket_write($this->sock, $messageStr, strlen($messageStr));
	}
}

public function readReply()
{
	if($this->connected)
	{
		$out = "";
		$msgSizeBytes = socket_read($this->sock, 2);
		$messageSize = ord($msgSizeBytes[0]);
		$messageSize = $messageSize << 8;
		$messageSize += ord($msgSizeBytes[1]);

		$bytesLeft = $messageSize;

		while($bytesLeft > 0)
		{
			if($bytesLeft > 2048)
				$out .= socket_read($this->sock, 2048);
			else
				$out .= socket_read($this->sock, $bytesLeft);
				
			$bytesLeft -= 2048;
		}
		
		$messageParts = explode("$",$out);
		$out = substr($out, strlen($messageParts[0])+1);
		return $out;
	}
	return "Error, connection closed";
}
	

}