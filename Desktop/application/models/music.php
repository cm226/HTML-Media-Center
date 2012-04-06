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
		$playlistq = "SELECT playlistName FROM Playlist";
		return $this->query($playlistq);
	
	}

	function cratePlaylist($playlistName)
	{
		$playlistq = "INSERT INTO Playlist VALUES('". $playlistName. "',0)";
		$this->query($playlistq);
	}
	
}
