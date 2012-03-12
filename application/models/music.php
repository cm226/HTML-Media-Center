<?php

class Music extends Model {
	
	function viewAll()
	{
		$allArtists = array( array("Avenged Sevenfold", "Awsome",5,1),
							array("Spineshank", "Metal", 3,1),
							array("Spineshank", "Metal", 3,1),
							array("Spineshank", "Metal", 3,1),
							array("Spineshank", "Metal", 3,1),
							array("Avenged Sevenfold", "Awsome",5,1),
							array("Spineshank", "Metal", 3,1),
							array("Avenged Sevenfold", "Awsome",5,1),
							array("Spineshank", "Metal", 3,1),
							array("Avenged Sevenfold", "Awsome",5,1),
							array("Spineshank", "Metal", 3,1),
							array("Avenged Sevenfold", "Awsome",5,1),
							array("Spineshank", "Metal", 3,1),
							array("Avenged Sevenfold", "Awsome",5,1),
						   );
						   
		return $allArtists;
									
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
	
	function getPlayLists ()
	{
		$playlists = array (
								"PlayList1",
								"PlayList2",
								"PlayList3"
							);
							
		return $playlists;
	
	}
	
}