<?php

class picture extends model
{
	function albumList()
	{
		$albumListq = "SELECT albumName FROM PictureAlbum";
		return $this->query($albumListq);
	}
	
}
