<?php

class Music extends Model {
	
	function viewAll()
	{
	
		$allArtistsq = 'SELECT artistName, artistID, artistRating, genre FROM Artist';
		$allArtistsResult = $this->query($allArtistsq);
		return $allArtistsResult;
									
	}
	
	function view($shearchCriteria)
	{
		
	}
	
	function getArtistsSongs($artistID)
	{
		$allArtistsSongq = "SELECT songName,
									songURL,
									Album.albumName,
									Artist.artistName,
									songLength
							FROM Song,
								 Album,
								 Artist
    						 WHERE
								Album.albumID = Song.albumID AND 
								Album.artistID = $artistID AND
								Artist.artistID = Album.artistID"; 
								
		$allArtistsSongResult = $this->query($allArtistsSongq);
		return $allArtistsSongResult;
	}
	
	function getArtistsAlbumSongs($artistName, $albumName)
	{
		$allArtistsSongq = 'SELECT 
								songName,
								songURL,
								Album.albumName,
								Album.artistName,
								songLength
								
							FROM Song,
								 Album

							 WHERE Album.albumID = Song.albumID 
								AND Album.artistName = \''.$artistName.'\'
								AND Album.albumName = \''. $albumName . '\'';
								
		$albumQueeryRes = $this->query($allArtistsSongq);
		
		return $albumQueeryRes;
	}
	
	function getArtistsAlbums($artistID)
	{
		$albumQueery = "SELECT  albumID,
								albumName,
								year,
								albumRating, 
									(SELECT 
										count(*) 
									FROM 
										Song
									WHERE Album.albumID = Song.albumID) as trackCount
						FROM 
								Album
						WHERE
								artistID = $artistID";
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
					Song.songName,
					Song.songLength,
					Song.songURL,
					Album.albumName,
					Album.artistName
				   FROM 
					Song,
					PlaylistSong,
					Album
				   WHERE 
					    PlaylistSong.playlistName = '$playlist'
					AND Song.songURL = PlaylistSong.songID
					AND Album.albumID = Song.albumID";

		return $this->query($playlistSongsq);
	}

	function filterSongs($Artist, $Song)
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
				    AND Song.albumID = Album.albumID";
		if($Artist != '')
			$filterSongsq .= " AND Artist.artistName = '$Artist'";
		if($Song != '')
			$filterSongsq .= " AND Song.songName = '$Song'"; // deff have to update this to use some heuristic like thing

		return $this->query($filterSongsq);
	}


	function isInPlayList($songURL, $playList)
	{
		$isInPlaylistq = "SELECT playlistSongID FROM PlaylistSong WHERE songID='$songURL' AND playlistName='$playList'";
		return (count($this->query($isInPlaylistq))>0 ? true : false);
	}

	function addSongsToPlayList($playlistName, $URLlist)
	{
		$insertValues = "";
		foreach ($URLlist as $url)
		{
			if(!$this->isInPlayList($url,$playlistName))
				$insertValues .= "('','$playlistName', '$url'),";
		}

		$AddToPlaylistsq = "INSERT INTO PlaylistSong VALUES ".substr($insertValues, 0, -1);
		$this->query($AddToPlaylistsq);
	}
	
	function get10RandomSongs()
	{
		$select5RandomSongs = "SELECT 
								songName,
								songURL,
								Album.albumName,
								Artist.artistName,
								songLength
								
							FROM Song,
								 Album,
								 Artist
							WHERE
								Song.albumID = Album.albumID
							ORDER BY RAND()
							LIMIT 10";
							
		return $this->query($select5RandomSongs);
		
	}

	function getArtistForID($artistID)
	{
		$q = "SELECT artistName FROM Artist WHERE artistID = $artistID";
		return $this->query($q);
		
	}
	
}
