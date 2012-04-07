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

	function getSongsFromPlayList($playlist)
	{
		$playlistSongsq = "SELECT 
					songName,
					songLength,
					songURL
				   FROM 
					Song,
					PlaylistSong
				   WHERE 
					    PlaylistSong.playlistName = '$playlist'
					AND Song.songURL = PlaylistSong.songID";

		return $this->query($playlistSongsq);
	}

	function filterSongs($searchData)
	{
		$filterSongsq = "SELECT 
					Song.songName,
					Song.songURL
				 FROM
					Song,
					Artist,
					Album
				 WHERE
					Artist.artistName = Album.artistName
				    AND Song.albumName = Album.albumName
				    AND Artist.artistName = 'Nickleback'"; // change this later its not finished

		return $this->query($filterSongsq);
	}

	function addSongsToPlayList($playlistName, $URLlist)
	{
		$insertValues = "";
		foreach ($URLlist as $url)
		{
			$insertValues .= "('','$playlistName', '$url'),";
		}

		$AddToPlaylistsq = "INSERT INTO PlaylistSong VALUES ".substr($insertValues, 0, -1);
		$this->query($AddToPlaylistsq);
	}
	
}
