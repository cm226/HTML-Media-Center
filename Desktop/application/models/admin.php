<?php

class Admin extends Model
{

	// -----------------------TV functions -------------------------------
	function seriseList()
	{
		$seriseListQ = "SELECT seriesName FROM Series";
		$seriesRes = $this->query($seriseListQ);
		return $seriesRes;
	}
	
	function seasonList($seriesName)
	{
		$seriesNumbersQ = "SELECT seriesNumber FROM Season WHERE seriesName = '". $seriesName ."'";
		$seriesNumbersRes = $this->query($seriesNumbersQ);
		return $seriesNumbersRes;
	}
	
	function createSeriesIfNecessary($Series)
	{	
		echo "SELECT seriesName FROM Series WHERE seriesName = '" . $Series. "'";
		if(count($this->query("SELECT seriesName FROM Series WHERE seriesName = '" . $Series. "'")) == 0)
			{
				$createq = "insert into Series values('". $Series ."', 10, '2010', '')";
				$this->query($createq);
			}
	}
	
	function createSeasonIfNecessary($Series, $Season)
	{
		
		$seasonq = "SELECT seasonID FROM Season WHERE seriesName = '$Series' AND seriesNumber = $Season";

		echo $seasonq;
		$seasonRes = $this->query($seasonq);
		
		if(count($seasonRes) > 0)
			return $seasonRes;
		
		else
		{
			$addSeasonq = "INSERT INTO Season values('','$Series',$Season)";
			echo $addSeasonq;
			$addSeasonRes = $this->query($addSeasonq);
			
			$seasonRes = $this->query($seasonq);
			if(count($seasonRes) > 0)
				return $seasonRes;
			
			else
				echo 'problem adding series';
		}
	}
	
	function createEpisode($epName,
							$epLengh,
							$playCount,
							$seasonID,
							$epURL,
							$epNumber)
	{
		$epQueery = "INSERT INTO Episode Values('$epName',
									'$epLengh',
									$playCount,
									$seasonID,
									'$epURL',
									$epNumber)";
									
									
		$this->query($epQueery);
	
	}

	// -----------------------Picture functions -------------------------------
	function albumList()
	{
		$albumListq = "SELECT albumName FROM PictureAlbum";
		return $this->query($albumListq);
	}

	function createAlbumIfNecessary($album)
	{
		$albumExsistsq = "SELECT albumName FROM PictureAlbum WHERE albumName = '" . $album . "'";
		if(count($this->query($albumExsistsq)) > 0)
			return; 

		$albumCreateq = "INSERT INTO PictureAlbum Values ('".$album."')";
		$this->query($albumCreateq);
	}

	function createPicture($name,
				$url,
				$album)
	{
		$createPicq = "INSERT INTO Picture VALUES('" .$name . "','" .$url . "','" .$album . "')";
		$this->query($createPicq);

	}

	// -----------------------Music functions -------------------------------

	function createArtistIfNecessary()
	{

	}
	function createAtristAlbumIfNecassery()
	{
	
	}
	function createSong()
	{

	}
}
