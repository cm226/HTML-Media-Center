<?php

class Movie extends Model {
	
	function viewAll()
	{
		$allMoviesq = "SELECT
			movieURL,		
			movieID,
			movieName,
			movieIMDB,
			movieLength,
			movieGenre,
			thumbnailURL
			
		FROM 
			Movie";
			
		return $this->query($allMoviesq);
	}
	
	function getVideoAgents()
	{
		
		$Agents;
		$sock = socket_create(AF_INET, SOCK_DGRAM, SOL_UDP);
		socket_set_option($sock, SOL_SOCKET, SO_BROADCAST, 1); 
		$timeout = array('sec'=>1,'usec'=>0);
  		socket_set_option($sock ,SOL_SOCKET,SO_RCVTIMEO,$timeout);
		
		
		$msg = "AGENT_HELLO_BROADCAST";
    	$len = strlen($msg);
		socket_sendto($sock, $msg, $len, 0, '192.168.0.198', 40002);

		$recv = "";

		$size=socket_recvfrom($sock,$recv,65535,0,$ipaddress,$port);
		
		if($recv=="")
			$Agents = array(array("IP"=>"no Connections","Location"=>"no Connections","Name"=>"no Connections"));
		else
			$Agents = array(array("IP"=>$ipaddress,"Location"=>"CraigsBedroom","Name"=>"TV"));
		
		return $Agents;
	}
	
	
	function getMovieWithID($movieID)
	{
		$movieq = "SELECT 
			movieURL,
			movieID,
			movieName,
			movieIMDB,
			movieLength,
			movieGenre,
			thumbnailURL
			
		FROM 
			Movie
		WHERE
			movieID =".$movieID;
			
		return $this->query($movieq);
	}
	
}
