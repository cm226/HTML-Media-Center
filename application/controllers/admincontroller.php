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
		|| ($_FILES["file"]["type"] == "video/x-msvideo")
		|| ($_FILES["file"]["type"] == "image/jpeg"))
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
			if(!file_exists("../public/mix/shows/".$series."/"))
				mkdir("../public/mix/shows/".$series."/");
				
			if(!file_exists("../public/mix/shows/".$series."/".$Season))
				mkdir("../public/mix/shows/".$series."/".$Season);
			if(!file_exists("../public/mix/shows/".$series."/".$Season."/".$name))
			{
				$oldURL = self::TEMP_FOLDER."TV/".$oldEpName;
				$newURL = "../public/mix/shows/".$series."/".$Season."/".$name;
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

	function uploadMusic()
	{
		if ((($_FILES["file"]["type"] == "audio/mp3"))
		)
		  {
		  if ($_FILES["file"]["error"] > 0)
			{
				$this->set("ReturnCode: ",$_FILES["file"]["error"]);
			}
		  else
			{
				$this->set("Upload", $_FILES["file"]["name"]);
				$this->set("Type",$_FILES["file"]["type"]);
				$this->set("Size", ($_FILES["file"]["size"] / 1024 / 1024));
				$this->set("Temp file",$_FILES["file"]["tmp_name"]);
				
				$this->set("seriesList", $this->Admin->seriseList());
				
			if (file_exists(self::TEMP_FOLDER."Music/" . $_FILES["file"]["name"]))
			  {
				$this->set("exists",true);
				echo "exists";
			  }
			else
			  {
				  move_uploaded_file($_FILES["file"]["tmp_name"],
				  self::TEMP_FOLDER."Music/" . $_FILES["file"]["name"]);
				  $this->set("Location",self::TEMP_FOLDER."Music/" . $_FILES["file"]["name"]);
				  $ip=$_SERVER['REMOTE_ADDR'];
				  $hostname = gethostname();
				  $myFile = "../tempUploads/data.log";
				  $fh = fopen($myFile, 'a') or die("can't open file");
				  $stringData = "".date("d.m.y")." Name: ".$_FILES["file"]["name"].", Type: ".$_FILES["file"]["type"].", Size: ".($_FILES["file"]["size"] / 1024 / 1024).", Hostname: ".$hostname." ".$ip."\n\n";
				  fwrite($fh, $stringData);
			  }
			}
		  }
		else
		  {
			$this->set("InvalidFileType",true);
		  }
	}

}
