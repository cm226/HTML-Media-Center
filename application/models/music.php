<?php

class Music extends Model {
	
	function viewAll()
	{
	
		$allArtistsq = 'SELECT artistName, artistRating, genre FROM Artist';
		$allArtistsResult = $this->query($allArtistsq);
		return $allArtistsResult;
									
	}
	
	function view($shearchCriteria)
	{
		
	}
	
	function getArtistsSongs($artistName)
	{
		
<<<<<<< HEAD
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
=======
		$allArtistsSongq = 'SELECT songName, songURL, Album.albumName, songLength FROM Song, Album WHERE Album.albumName = Song.albumName AND Album.artistName = \''.$artistName.'\''; 
		$allArtistsSongResult = $this->query($allArtistsSongq);
		return $allArtistsSongResult;
	}
	
	function getArtistsAlbumSongs($artistName, $albumName)
	{
		$allArtistsSongq = 'SELECT 
								songName,
								songURL,
								Album.albumName,
								songLength
								
							FROM Song,
								 Album

							 WHERE Album.albumName = Song.albumName 
								AND Album.artistName = \''.$artistName.'\'
								AND Album.albumName = \''. $albumName . '\'';
								
		$albumQueeryRes = $this->query($allArtistsSongq);
		
		return $albumQueeryRes;
>>>>>>> 8d3a9637a30c37e5f2341c02f83ac25642310f8b
	}
	
	function getArtistsAlbums($artistName)
	{
		$albumQueery = "SELECT  albumName,
								year,
								albumRating, 
									(SELECT 
										count(*) 
									FROM 
										Song
									WHERE Album.albumName = Song.albumName) as trackCount
						FROM 
								Album
						WHERE
								artistName = '$artistName'";
		$albumQueeryRes = $this->query($albumQueery);
		
		
		return $albumQueeryRes;
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