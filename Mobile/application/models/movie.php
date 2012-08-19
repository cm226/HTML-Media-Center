<?php

class Movie extends Model {
	
	function viewAll()
	{
		$allMoviesq = "SELECT 
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
		//$Agents = array(array("IP"=>"192.168.0.198","Location"=>"LivingRoom","Name"=>"TV"));
		$Agents = array(array("IP"=>"127.0.0.1","Location"=>"LivingRoom","Name"=>"TV"));
		return $Agents;
	}
	
	
	function getMovieWithID($movieID)
	{
		$movieq = "SELECT 
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