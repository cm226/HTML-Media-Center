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
		return false;
	}
	
	if (socket_connect($this->sock, $this->address, $port) == false) 
	{
		return false;
	}
  
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
		$chunckSize = 0xFFFF;
		
		if($msgLen > $chunckSize)
		{
			$numChunks = Ceil($msgLen / $chunckSize);
		}
		else
		{
			$numChunks = 1;
		}
		
		socket_write($this->sock, chr($numChunks & 255),1);
		
		for($i = 0; $i < $numChunks; $i++)
		{	
			$chunckStart = $i*$chunckSize;
			
			if(($chunckStart + $chunckSize) < $msgLen)
				$chunckEnd = $chunckStart + $chunckSize;
			else
				$chunckEnd = $chunckStart + ($msgLen - $chunckStart);
				
			$chunckLength = $chunckEnd - $chunckStart;
			
			$lowBit = $chunckLength & 255;
			$hightBit = $chunckLength >> 8;
			
			$msgHeaderStr = chr($hightBit). chr($lowBit);
			
			$messageChunck = $msgHeaderStr . substr($messageStr,$chunckStart, $chunckEnd - $chunckStart);
			socket_write($this->sock, $messageChunck, strlen($messageChunck));
		}
	}
}

public function readReply()
{
	if($this->connected)
	{		
		$msgSizeBytes = socket_read($this->sock, 2);
		$messageSize = ord($msgSizeBytes[0]);
		$messageSize = $messageSize << 8;
		$messageSize += ord($msgSizeBytes[1]);

		$read_chunk_size = 2048;
		$bytesLeft = $messageSize;
		
		$out_chunks = array((int)ceil($messageSize/$read_chunk_size));
		
		$read_chunk_counter = 0;
		while($bytesLeft > 0)
		{
			if($bytesLeft > $read_chunk_size)
			{
				$out_chunks[$read_chunk_counter] = socket_read($this->sock, $read_chunk_size);
				$read_size = strlen($out_chunks[$read_chunk_counter]);
				
				if( $read_size != $read_chunk_size) // sometimes php will read the data faster than the C++ can write it, so make sure that we have read the whole chunck
					$out_chunks[$read_chunk_counter] .= socket_read($this->sock, $read_chunk_size - $read_size);
					
			}
			else
			{
				$out_chunks[$read_chunk_counter] = socket_read($this->sock, $bytesLeft);
			}
				
			$bytesLeft -= $read_chunk_size;
			$read_chunk_counter++;
		}
		
		
		$out = implode($out_chunks);
		
		$messageParts = explode("$",$out);
		
		$out = substr($out, strlen($messageParts[0])+1);
		
		return $out;
	}
	return "Error, connection closed";
}
	

}
