<?php
require_once (ROOT . DS . 'application' . DS . 'views' . DS . 'Shared'.DS.'download.php');

class MusicController extends Controller {
	
	function viewall()
	{
		if(isset($_POST['newPlaylist']))
		{
			$this->Music->cratePlaylist($_POST['newPlaylist']);
			unset($_POST['newPlaylist']);
		}
			
		$this->set('artists',$this->Music->viewAll());
		$this->set('playlists', $this->Music->getPlayLists());
		$this->set('recentlyAddedSongs', $this->Music->getRecentlyAdded());
	}
	
	function viewArtist($artistID)
	{
		$artistName = $this->Music->getArtistForID($artistID);
		$artistName = $artistName[0]['Artist']['artistName'];
		$this->set('artistsName',$artistName);
		$this->set('artistID',$artistID);
		$this->set('albums',$this->Music->getArtistsAlbums($artistID));
		
	}
	
	function viewPlayer($artistID)
	{
		$funcArgs = func_get_args();
		
		if($funcArgs[0] == 'takethisout')
		{
			if($funcArgs[1] == 'album')
			{
				$artistID = 
				$this->set('songs',$this->Music->getAlbumSongs($funcArgs[2]));
			}

		}	
		else // this is the old way phase out
		{
		if($artistID == "") // hack for view shuffle
		{
			$this->set("songs", $this->Music->get10RandomSongs());
			return;
		}
	
		if(isset($_POST['playlist'])) // viewing a playlist
		{
			$this->set('songs',$this->Music->getSongsFromPlayList($_POST['playlist']));	
			return;
		}
		
		if(isset($_POST['recentlyAdded']))
		{
			$this->set('songs',$this->Music->getRecentlyAdded());	
			return;
		}
		
		// viewing an artist
		if(!isset($_POST['album']))
		{
			$this->set('songs',$this->Music->getArtistsSongs($artistID));
		}
		}


	}

	function viewPlaylist($playlist) //improve this whole thing by using AJAX and each result has a submit button
	{
		if(isset($_POST['Song']) || isset($_POST['Artist']))
		{	
			$Song = isset($_POST['Song']) ? $_POST['Song'] : '';
			$Artist = isset($_POST['Artist']) ? $_POST['Artist'] : '';

			$this->set("searchResults",$this->Music->filterSongs($Artist,$Song));
			unset($_POST['Song']);
			unset($_POST['Artist']);
		}
		else if (isset($_POST['res1']))
		{
			$resName = "res";
			$resURL = "resURL";
			$count = 0;
			$urlList = array();

			for ($count=0 ; $count < 20; $count++) // limit search results to 20
			{
				if(!isset($_POST[$resName.$count]))
					continue;
				if($_POST[$resName.$count] == 'on')
				{
					array_push($urlList,$_POST[$resURL.$count]);
				}
			}

			$this->Music->addSongsToPlayList($playlist,$urlList);
		}
		$this->set("playlistName", $playlist);
	}
	
	function viewShuffle()
	{
		
	}
	
	function downloadSong($songID)
	{
		$res = $this->Music->getSongForID($songID);
		$fileURL = ROOT . DS . 'public'. str_replace("/","\\",str_replace("../public","", $res[0]['Song']['songURL']));
		$this->set("file",$fileURL);
	}
	
	function playAudioStream()
	{
		$songList =  $_POST['songs'];
		$this->set("reply",$this->Music->streamPlaylist($songList));
		
	}

	function makeAgentQuery()
	{
		$agents = $this->Music->makeAgentRequest();
		$this->set('agents',$agents);
	}

	function viewAlbums()
	{
		$albums = $this->Music->getAlbums();
		$this->set('albums',$albums);
	}

	function viewAlbum($albumID)
	{
		$album = $this->Music->getAlbumForID($albumID);
		$this->set('album', $album[0]);
	}

}
