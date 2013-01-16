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
		$msg = "AGENT_HELLO_BROADCAST";
    		$len = strlen($msg);
		socket_sendto($sock, $msg, $len, 0, '0', 40002);

		$recv = "";

		$size=socket_recvfrom($sock,$recv,65535,0,$ipaddress,$port);
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
