<?php

class MusicController extends Controller {
	
	function viewall()
	{
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
		$this->set('songs',$this->Music->getArtistsSongs($artistName));
	}
}
