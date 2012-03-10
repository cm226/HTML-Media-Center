<?php

class Music extends Model {
	
	function viewAll()
	{
		$allMovies = array( array("Avenged Sevenfold", "Awsome",5),
							array("Spineshank", "Metal", 3)
						   );
						   
		return $allMovies;
									
	}
	
	function view($shearchCriteria)
	{
		
	}
	
	function getArtistsSongs($artistName)
	{
		
		$songURLs = array(array(
									"Url"    => "../public/mix/04-info-recall.mp3",
									"Name"   => "Bat Country",
									"Album"  => "Bat country",
									"Length" =>"3:15"),
						  array(
									"Url"    => "../public/mix/04-info-recall2.mp3",
									"Name"   => "cafddds",
									"Album"  => "Bat country",
									"Length" =>"3:15")
						);
		return $songURLs ;
	}
	
	function getArtistsAlbums($artistName)
	{
		$albumNames = array("Bat Country",
							"another album",
							"yet another album");
							
		return $albumNames;
	}
	
}