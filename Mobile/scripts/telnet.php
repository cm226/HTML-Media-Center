<?php

// this file opens a telnet connection to a vlc player if the vlc interface had been started
// if not it starts it, then starts streaming the media file VOD style

$pass = 'mediaPWLOL';
$port = '4212';
$socket;

function openSocket($host)
{
	$socket = fsockopen($host, $port) or die('Could not connect to: '.$host);
}

function telnet_vlc_addmedia($videoName, $videoURL,$password, $hostIP)
{
	for($i = 0; $i <=1; $i++)
	{
		  $line = fgets($socket, 1024);
		  echo "socket Text: ".$line."\n";
			// Code to deal with the output.
			switch($line)
			 {
			  case 'user:':
			   fputs($socket, $user."\r\n");
			  break;

			  case 'password:':
			   fputs($socket, $pass."\r\n");
			  break;
			  
			 default:
			  // do nothing
		   }
	   }
	   echo "socket Text: ".$line."\n";
	   fputs($socket,"new $videoName vod enabled \r\n");
	   $line = fgets($socket, 1024);
	   	   echo "socket Text: ".$line."\n";
	   fputs($socket,"setup $videoName intput $videoURL");
	   $line = fgets($socket, 1024);
	   	   echo "socket Text: ".$line."\n";
	   fputs($socket,"setup $videoName output  #standard{access=http,mux=ts,dst=$hostIP:8080/$videoName}");
	   $line = fgets($socket, 1024);
	   	   echo "socket Text: ".$line."\n";
	   
	   fclose ($socket);
	 
 }

?>
