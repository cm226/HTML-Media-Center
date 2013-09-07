<?php
require_once("../scripts/JARVISCOMS/JARVIS.Comms.php");
require_once("../scripts/JARVISCOMS/Messages/RequestStreamMediaMessage.php");
require_once("../scripts/JARVISCOMS/Messages/AgentRequestMessage.php");

class Music extends Model {
	
	function viewAll()
	{
	
		$allArtistsq = 'SELECT artistName, artistID, artistRating, genre FROM Artist ORDER BY artistName';
		$allArtistsResult = $this->query($allArtistsq);
		return $allArtistsResult;
									
	}
	
	function view($shearchCriteria)
	{
		
	}
	
	function getArtistsSongs($artistID)
	{
		$allArtistsSongq = "SELECT Song.songID,
									songName,
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

	function getAlbums()
	{
		$albumsQ = "SELECT Album.albumID,
				   Album.albumName,
				   Album.year,
				   Album.albumRating,
				   Artist.artistName
			    FROM Album, Artist
			    WHERE Album.artistID = Artist.artistID
				ORDER BY Album.albumName";	

		return $this->query($albumsQ);
	}
	
	function getAlbumSongs($albumID)
	{
		$allArtistsSongq = 'SELECT Song.songID, 
								songName,
								songURL,
								Album.albumName,
								Artist.artistName,
								songLength
								
							FROM Song,
								Album,
								Artist

							 WHERE  Album.artistID = Artist.artistID 
								AND Album.albumID = Song.albumID 
								AND Album.albumid = \''. $albumID . '\'';
								
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
					Song.songID,
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
								Song.songID,
								songName,
								songURL,
								Album.albumName,
								Artist.artistName,
								songLength
								
							FROM Song,
								 Album,
								 Artist
							WHERE
								Song.albumID = Album.albumID AND
								Album.artistID = Artist.artistID
							ORDER BY RAND()
							LIMIT 10";
							
		return $this->query($select5RandomSongs);
		
	}

	function getArtistForID($artistID)
	{
		$q = "SELECT artistName FROM Artist WHERE artistID = $artistID";
		return $this->query($q);
		
	}
	
	function getSongForID($ID)
	{
		$q = "SELECT * FROM Song WHERE songID = ".$ID;
		return $this->query($q);
	}

	function getAlbumForID($albumID)
	{
		$q = "SELECT * From Album WHERE albumID = ".$albumID;
		return $this->query($q);
	}
	
	function getRecentlyAdded()
	{
		$q = "SELECT 
				Song.songID,
				songName,
				songURL,
				Album.albumName,
				Artist.artistName,
				songLength
				
		 	  FROM 
		 		Song,
				Album,
				Artist
			  WHERE
			  	Song.albumID = Album.albumID AND
				Artist.artistID = Album.artistID
			  ORDER BY dateAdded DESC LIMIT 10";
		return $this->query($q);
	}

	function streamPlaylist($playlist)
	{
		$playlistArray=explode(',',$playlist);
		$comms = new JARVISCommas();

		return $comms->send(new RequestStreamMediaMessage($playlistArray));
		
	}

	function makeAgentRequest()
	{
		$comms = new JARVISCommas();
		$agents = $comms->send(new AgentRequestMessage());
		return explode(',',$agents);
	}
	
}
