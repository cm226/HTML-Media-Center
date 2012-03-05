<?php

class Movie extends Model {
	
	function viewAll()
	{
		$allMovies = array( array("Batman", "Action",'10:27:49'),
							array("AmericanPie", "Action", '6:74:20')
						   );
						   
		return $allMovies;
									
	}
	
	function view($shearchCriteria)
	{
		$result = array("Batman", "Action",'10:27:49');
		return $result;
	}
	
}