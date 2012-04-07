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
		$artistName = $_POST['artist'];
		$this->set('artistsName',$artistName);
		$this->set('albums',$this->Music->getArtistsAlbums($artistName));
		
	}
	
	function viewPlayer()
	{
		$artistName = $_POST['artist'];
		$this->set('artistsName',$artistName);
		if(!isset($_POST['album']))
			$this->set('songs',$this->Music->getArtistsSongs($artistName));
		else
			$this->set('songs',$this->Music->getArtistsAlbumSongs($artistName,$_POST['album']));
	}

	function viewPlaylist($playlist) //improve this whole thing by using AJAX and each result has a submit button
	{
		if(isset($_POST['search']))
		{	
			$this->set("searchResults",$this->Music->filterSongs($_POST['search']));
			unset($_POST['search']);
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
		$this->set("songs", $this->Music->getSongsFromPlayList($playlist));
	}
}
