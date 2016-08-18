<?php

class PicturesController extends Controller {
	
	function albums()
	{
		$this->set('albums',$this->Picture->albumList());
	}

	function viewAlbum($albumName)
	{
		$this->set('albumName',$albumName);
		$this->set('pictureDetails', $this->Picture->getPicDetails($albumName));
	}

}
