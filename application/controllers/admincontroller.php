<?php

class AdminController extends Controller
{
	function Main()
	{
		
	}
	
	function uploadTv()
	{
		if ((($_FILES["file"]["type"] == "video/avi")
		|| ($_FILES["file"]["type"] == "video/mp4")
		|| ($_FILES["file"]["type"] == "video/wmv"))
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
				
			if (file_exists("../../Public/mix/shows/tmp/TV/" . $_FILES["file"]["name"]))
			  {
				$this->set("exsists",true);
			  }
			else
			  {
			  move_uploaded_file($_FILES["file"]["tmp_name"],
			  "../public/mix/shows/tmp/TV/" . $_FILES["file"]["name"]);
			  $this->set("Location","../../Public/mix/shows/tmp/TV/" . $_FILES["file"]["name"]);
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
		
		
	}

}