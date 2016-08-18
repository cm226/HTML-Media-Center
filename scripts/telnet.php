<?php

// this file opens a telnet connection to a vlc player if the vlc interface had been started
// if not it starts it, then starts streaming the media file VOD style


function openSocket($host,$port)
{
	$socket = fsockopen($host, $port) or die('Could not connect to: '.$host);
	if($socket)
		return $socket;
	else
	{	
		echo "failed to connect ";
		return false;
	}
}

function telnet_vlc_addmedia($socket, $videoName, $videoURL,$password, $hostIP)
{
	//stream_set_blocking ($socket ,0);
	 stream_set_timeout($socket,5);

	$line = fread($socket, 1024);
	echo "socket Text: ".$line."\r\n";
	fputs($socket, $password."\r\n");

	readTillInput($socket);
	echo "pwtext Text: ".$line."\r\n";


	fputs($socket,"new $videoName broadcast enabled \r\n");
	readTillInput($socket);
	
	echo "writing: setup $videoName input $videoURL";
	fputs($socket,"setup $videoName input $videoURL\r\n");
	readTillInput($socket);


	/*fputs($socket,"setup $videoName output  #standard{access=http,mux=ts,dst=$hostIP:8080/$videoName}");
	$line = fread($socket, 1024);
	echo "socket Text: ".$line."\n";


	fputs($socket,"control $videoName play");
	$line = fread($socket, 1024);
	echo "play Text: ".$line."\n";*/

//	sleep(2);
	
	//echo "setup $videoName input $videoURL";
//	echo "setup Input Text: ".$line."\n";
	   
//	

	
	

	  /* echo "socket Text: ".$line."\n";
	   fputs($socket,"new $videoName vod enabled \r\n");
	   $line = fgets($socket, 1024);
	   	   echo "socket Text: ".$line."\n";
	   fputs($socket,"setup $videoName intput $videoURL");
	   $line = fgets($socket, 1024);
	   	   echo "socket Text: ".$line."\n";
	   fputs($socket,"setup $videoName output  #standard{access=http,mux=ts,dst=$hostIP:8080/$videoName}");
	   $line = fgets($socket, 1024);
	   	   echo "socket Text: ".$line."\n";*/
	   
	   fclose ($socket);
	 
 }

function readTillInput($socket)
{
	$line = fread($socket, 1024);
	if(!$line)
		return;
	echo "socket Text: ".$line."\r\n";
	while(!strstr($line,'>') || !strstr($line,'setup'))
	{
		$line = fread($socket, 1024);
		if(!$line)
			return;
		echo "socket Text: ".$line."\r\n";
	}
	return;
}



?>
