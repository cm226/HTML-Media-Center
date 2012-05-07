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

	function createArtistIfNecessary($ArtistName)
	{
		$artistExistsq = "SELECT artistName FROM Artist WHERE artistName = '$ArtistName'";
		if(count($this->query($artistExistsq)) > 0)
			return;

		$addArtistq = "INSERT INTO Artist VALUES('$ArtistName', 10, 'unknown')";
		echo $addArtistq;
		$this->query($addArtistq);
		
	}
	function createAtristAlbumIfNecassery($ArtistName, $AlbumName)
	{
		$albumExsistsq = "SELECT albumName FROM Album WHERE albumName='$AlbumName' AND artistName= 'ArtistName'";
		if(count($this->query($albumExsistsq)) > 0)
			return;

		$addAlbumq = "INSERT INTO Album VALUES ('$AlbumName', '$ArtistName', '2010' , 10)";
		echo $addAlbumq;
		$this->query($addAlbumq);
	}

	function createSong($songName, $ArtistName, $AlbumName, $URL)
	{
		$songExsistsq = "SELECT songName FROM Song WHERE songName ='$songName' AND 
									albumName = '$AlbumName'";

		echo $songExsistsq;
		if(count($this->query($songExsistsq)) > 0)
			return;

		$addSongq = "INSERT INTO Song VALUES ('$songName', '$AlbumName', '03:50:00', 10, 0, '$URL')";
		echo $addSongq;
		$this->query($addSongq);
	}

	function getArtistsList()
	{
		$artistListq = "SELECT artistName FROM Artist";
		return $this->query($artistListq);
	}

	function getAlbums($artist)
	{
		$getAlbumsq = "SELECT albumName FROM Album WHERE artistName = '$artist'";
		return $this->query($getAlbumsq);
	}

	//-----------------------------------GENERIC---------------------------------

	function googleImageResults($k)
	{
		$url = "https://ajax.googleapis.com/ajax/services/search/images?" .
		       "v=1.0&q=". $k ."&userip=INSERT-USER-IP";

		// sendRequest
		// note how referer is set manually
		$ch = curl_init();
		curl_setopt($ch, CURLOPT_URL, $url);
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
		curl_setopt($ch, CURLOPT_REFERER, "http://localhost/HTML-Media-Center/");
		$body = curl_exec($ch);
		curl_close($ch);

		// now, process the JSON string
		$json = json_decode($body);
		// now have some fun with the results...

		//print_r ($json->{"responseData"}->{"results"}[0]->{"url"}) ;

		return $json->{"responseData"}->{"results"};
	}
}


