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
		
		$allArtistsSongq = 'SELECT songName, songURL, Album.albumName, songLength FROM Song, Album WHERE Album.albumName = Song.albumName AND Album.artistName = \''.$artistName.'\''; 
		$allArtistsSongResult = $this->query($allArtistsSongq);
		return $allArtistsSongResult;
	}
	
	function getArtistsAlbums($artistName)
	{
		$albumQueery = "SELECT albumName FROM Album WHERE artistName = '$artistName'";
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