<?php

class Transever
{



var $address = '127.0.0.1';
var $port = 45001;
var $sock;

function __construct() 
{
	error_reporting(E_ALL);
	/* Allow the script to hang around waiting for connections. */
	set_time_limit(0);
	/* Turn on implicit output flushing so we see what we're getting
	 * as it comes in. */
	ob_implicit_flush();

	if (($sock = socket_create(AF_INET, SOCK_STREAM, SOL_TCP)) === false)
	{
		echo "socket_create() failed: reason: " . socket_strerror(socket_last_error()) . "\n";
		return false;
	}
	
	if (socket_connect($sock, $address, $service_port) == false) 
	{
		echo "socket_listen() failed: reason: " . socket_strerror(socket_last_error($sock)) . "\n";
		return false;
	}
	return true;
}

function __destruct()
{
	if($sock)
	{
		socket_close($socket);
	}
}

public function sendMessage($Message)
{
	$messageStr = $Message->getMessage();
	socket_write($sock, $messageStr, strlen($messageStr));
}

public function readReply()
{
	$out = socket_read($socket, 2048);
	return $out;
}
	

}