<?php

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
	}
	
	function viewArtist()
	{
		$artistID = $_POST['artist'];
		$artistName = $this->Music->getArtistForID($artistID);
		$artistName = $artistName[0]['Artist']['artistName'];
		$this->set('artistsName',$artistName);
		$this->set('artistID',$artistID);
		$this->set('albums',$this->Music->getArtistsAlbums($artistID));
		
	}
	
	function viewPlayer()
	{
		if(isset($_POST['playlist'])) // viewing a playlist
		{
			$this->set('songs',$this->Music->getSongsFromPlayList($_POST['playlist']));	
			return;
		}
		// viewing an artist
		$artistID = $_POST['artist'];
		if(!isset($_POST['album']))
			$this->set('songs',$this->Music->getArtistsSongs($artistID));
		else
			$this->set('songs',$this->Music->getArtistsAlbumSongs($artistID,$_POST['album']));
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
}
