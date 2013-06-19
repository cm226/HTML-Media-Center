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
	
	function view($movieid)
	{
		$movieQ = "SELECT movieURL FROM Movie WHERE Movie.movieID = ".$movieid;
		return $this->query($movieQ);
	}
	
}