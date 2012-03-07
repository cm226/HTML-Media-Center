<?php

class MusicController extends Controller {
	
	function viewall()
	{
		$this->set('artists',$this->Music->viewAll());
	}
	
	function viewArtist()
	{
		$artistName = $_POST['artist'];
		$this->set('artistsName',$artistName);
		$this->set('songs',$this->Music->getArtistsSongs($artistName));
	}
}
