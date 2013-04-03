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
	
	function view($movieName)
	{
		$result = 'D:\Videos\Personal\MOV00041.mp4';
		return $result;
	}
	
}