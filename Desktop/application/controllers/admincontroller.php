<?php

class AdminController extends Controller
{
	const TEMP_FOLDER = '../tempUploads/';
	function Main()
	{
		
	}
	
	function uploadTv()
	{
		if ((($_FILES["file"]["type"] == "video/avi")
		|| ($_FILES["file"]["type"] == "video/mp4")
		|| ($_FILES["file"]["type"] == "video/wmv")
		|| ($_FILES["file"]["type"] == "video/x-msvideo"))
		)
		  {
		  if ($_FILES["file"]["error"] > 0)
			{
				$this->set("ReturnCode",$_FILES["file"]["error"]);
			}
		  else
			{
				$this->set("Upload", $_FILES["file"]["name"]);
				$this->set("Type",$_FILES["file"]["type"]);
				$this->set("Size", ($_FILES["file"]["size"] / 1024 / 1024));
				$this->set("Temp file",$_FILES["file"]["tmp_name"]);
				
				$this->set("seriesList", $this->Admin->seriseList());
				
			if (file_exists(self::TEMP_FOLDER."TV/" . $_FILES["file"]["name"]))
			  {
				$this->set("exsists",true);
			  }
			else
			  {
			  move_uploaded_file($_FILES["file"]["tmp_name"],
			  self::TEMP_FOLDER."TV/" . $_FILES["file"]["name"]);
			  $this->set("Location",self::TEMP_FOLDER."TV/" . $_FILES["file"]["name"]);
			  }
			}
		  }
		else
		  {
			$this->set("InvalidFileType",true);
		  }
	}
	
	function submitTVData()
	{

		$series = $_POST['Series'];
		$name  = $_POST['eName'];
		$Season  = $_POST['Season']; 
		$EpisodeNumber = $_POST['eNumber'];
		$oldEpName = $_POST['oldName'];

		echo $series;		
		if (file_exists(self::TEMP_FOLDER."TV/".$oldEpName))
		{
			if(!file_exists("../public/mix/Tv/".$series."/"))
				mkdir("../public/mix/Tv/".$series."/");
				
			if(!file_exists("../public/mix/Tv/".$series."/".$Season))
				mkdir("../public/mix/Tv/".$series."/".$Season);
			if(!file_exists("../public/mix/Tv/".$series."/".$Season."/".$name))
			{
				$oldURL = self::TEMP_FOLDER."TV/".$oldEpName;
				$newURL = "../public/mix/Tv/".$series."/".$Season."/".$name;
				if(rename($oldURL,$newURL))
				{
					$this->Admin->createSeriesIfNecessary($series);
					$seasonID = $this->Admin->createSeasonIfNecessary($series,$Season);
					$seasonID = $seasonID[0]['Season']['seasonID'];
					$this->Admin->createEpisode($name,
												"00:45:00",
												0,
												$seasonID,
												$newURL,
												$EpisodeNumber);
				}
				else
				{
					echo 'copy error';
					return;
				}
				
			}
			else
			{
				echo 'That file already exsists';
				return;
			}
		}
		
		
		$this->set("Sucess", true);
		$this->set("name", $name);
		
	}

	function uploadPicture()
	{
		if ((($_FILES["file"]["type"] == "image/jpeg")
		|| ($_FILES["file"]["type"] == "image/bmp")
		|| ($_FILES["file"]["type"] == "image/png")
		|| ($_FILES["file"]["type"] == "image/gif")
		|| ($_FILES["file"]["type"] == "image/tif"))
		)
		  {
		  if ($_FILES["file"]["error"] > 0)
			{
				$this->set("ReturnCode",$_FILES["file"]["error"]);
			}
		  else
			{
				$this->set("Upload", $_FILES["file"]["name"]);
				$this->set("Type",$_FILES["file"]["type"]);
				$this->set("Size", ($_FILES["file"]["size"] / 1024 / 1024));
				$this->set("Temp file",$_FILES["file"]["tmp_name"]);
				
				$this->set("albums", $this->Admin->albumList());
				
			if (file_exists(self::TEMP_FOLDER."Pictures/" . $_FILES["file"]["name"]))
			  {
				$this->set("exsists",true);
			  }
			else
			  {
			  $moved = move_uploaded_file($_FILES["file"]["tmp_name"],
					self::TEMP_FOLDER."Pictures/" . $_FILES["file"]["name"]);
			  
				echo $moved;
				if($moved)
					$this->set("Location",self::TEMP_FOLDER."Pictures/" . $_FILES["file"]["name"]);
				else
					{
						echo 'couldent move the uploaded file <br/>';
						echo 'the file was uploaded sucessfully : ' .  is_uploaded_file($_FILES["file"]["tmp_name"]);
					}
			  }
			}
		  }
		else
		  {
			$this->set("InvalidFileType",true);
		  }


	}

	function submitPictureData()
	{
		$PicName = $_POST['PicName'];
		$Album  = $_POST['Album'];
		$oldEpName = $_POST['oldName'];

		if (file_exists(self::TEMP_FOLDER."Pictures/".$oldEpName))
		{
			if(!file_exists("../public/mix/Pictures/".$Album."/"))
				mkdir("../public/mix/Pictures/".$Album."/");
				
			if(!file_exists("../public/mix/Pictures/".$Album."/".$PicName))
			{
				$oldURL = self::TEMP_FOLDER."Pictures/".$oldEpName;
				$newURL = "../public/mix/Pictures/".$Album."/".$PicName;
				if(rename($oldURL,$newURL))
				{
					$this->Admin->createAlbumIfNecessary($Album); // can be optimised by checking is new album is checked (cba do later)
					$this->Admin->createPicture($PicName,
									$newURL,
									$Album);
				}
				else
				{
					echo 'copy error';
					return;
				}
				
			}
			else
			{
				echo 'That file already exsists';
				return;
			}
		}
		
		
		$this->set("Sucess", true);
		$this->set("name", $PicName);
		
	}

	function tryAddMusicFile($file, $fileCount)
	{
		if( $file["error"] > 0)
		{
			$this->set("ReturnCode: ",$file["error"]);
		}
		else
		{
			$songName = $_POST['songName'. $fileCount].".mp3";
			$artistID  = $_POST['artistName'];
			$albumName = $_POST['filealbum'. $fileCount];
			$artistName = $this->Admin->getArtistForID($artistID);
			
			if (file_exists(PUBLIC_FOLDER."/mix/Music/".$artistName."/".$albumName."/".$songName))
			  {
				$this->set("exists",true);
				echo "exists";
			  }
			else
			  {
				  $this->submitMusicData($songName,$artistName[0]["Artist"]["artistName"], $albumName, $file["tmp_name"]);
				  
				  $this->set("Location",self::TEMP_FOLDER."Music/" . $file["name"]);
				  //$ip=$_SERVER['REMOTE_ADDR'];
				  //$hostname = gethostname();
				  //$myFile = "../tempUploads/data.log";
				  //$fh = fopen($myFile, 'a') or die("can't open file");
				  //$stringData = "".date("d.m.y")." Name: ".$file["name"].", Type: ".$file["type"].", Size: ".($_FILES["file"]["size"] / 1024 / 1024).", Hostname: ".$hostname." ".$ip."\n\n";
				  //fwrite($fh, $stringData);
			  }
		}
	}

	function uploadMusic()
	{
		$numOfFiles = count($_FILES);
		$filecount = 0;
		foreach($_FILES as $file)
		{
			if ($file["type"] == "audio/mp3" || $file["type"] == "audio/mpeg")
			{	
				$this->tryAddMusicFile($file, $filecount);
			}
			else
				$this->set("InvalidFileType",true);

			$filecount = $filecount+1;
		} 
	}

	function submitMusicData($songName,$artistName,$albumName, $oldfileName)
	{
		$artistImage = ''; // both not implemented yet
		$albumImage = '';
		
			if(!file_exists(PUBLIC_FOLDER."/mix/Music/".$artistName."/"))
				mkdir(PUBLIC_FOLDER."/mix/Music/".$artistName."/");

			if(!file_exists(PUBLIC_FOLDER."/mix/Music/".$artistName."/".$albumName."/"))
				mkdir(PUBLIC_FOLDER."/mix/Music/".$artistName."/".$albumName."/");
				
			if(!file_exists(PUBLIC_FOLDER."/mix/Music/".$artistName."/".$albumName."/".$songName))
			{
				$newURL =  PUBLIC_FOLDER."/mix/Music/".$artistName."/".$albumName."/".$songName;
				$moveWorked = move_uploaded_file($oldfileName,$newURL);
				if($moveWorked)
				{
					$artistID = $this->Admin->createArtistIfNecessary($artistName);
					$albumID = $this->Admin->createAtristAlbumIfNecassery($artistID, $albumName);
					$this->Admin->createSong($songName, $artistName, $albumID, $newURL);

					if($artistImage != '')
					{
						//$artistImageHandle = fopen($artistImage, "r");
						$extention = substr($artistImage, -3);
						//$downloadedFile = fopen(PUBLIC_FOLDER . DS .'img' . DS . 'Music' .DS . 'Artists' . DS .$artistName . 'BG.'. $extention, 'w');

						copy($artistImage,PUBLIC_FOLDER . DS .'img' . DS . 'Music' .DS . 'Artists' . DS .$artistName . 'BG.'. $extention);
					}

					if($albumImage != '')
					{
						
					}

				}
				else
				{
					echo 'copy error';
					return;
				}
				
			}
			else
			{
				echo 'That file already exsists';
				return;
			}
		
		
		$this->set("Sucess", true);
		$this->set("name", $songName);

	}
	
	function Music()
	{
		$this->set("ArtistList", $this->Admin->getArtistsList());
	}

	function MusicAddNewSongs()
	{
		$this->set("test",$this->Admin->getLastAutoIncrement());
		$this->set("ArtistList", $this->Admin->getArtistsList());
	}
	
	function uploadArtistPic()
	{
		$artistName = $_POST['artistName'];
		
		if ($_FILES["image"]["type"] == "image/png")
		{
			if ($_FILES["image"]["error"] > 0)
			{
				$this->set("ReturnCode",$_FILES["image"]["error"]);
			}
			
			 move_uploaded_file($_FILES["image"]["tmp_name"],
				  PUBLIC_FOLDER."/img/Music/Artists/".$artistName.".png");
		}
		else
			$this->set("invalidType", true);
	}

	function getArtistAlbums($artistName)
	{
		$this->set("Albums", $this->Admin->getAlbums($artistName));
	}

	function getArtistBackgrounds($artistName)
	{
		$results = $this->Admin->googleImageResults($artistName);
		$this->set("images", $results);
	}

	function addNewArtistAlbum($artistID)
	{
		
		
		
	}
}
