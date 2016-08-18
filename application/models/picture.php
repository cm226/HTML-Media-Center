<?php

class picture extends model
{
	function albumList()
	{
		$albumListq = "SELECT albumName FROM PictureAlbum";
		return $this->query($albumListq);
	}

	function getPicDetails($album)
	{
		$pictureDetails = "SELECT picName, picURL FROM Picture, PictureAlbum WHERE Picture.albumName = PictureAlbum.albumName AND Picture.albumName = '" . $album. "'";
		return $this->query($pictureDetails);
	}
	
}
