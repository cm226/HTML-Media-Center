FileName = <?php echo $Upload; ?>&nbsp;
FileSize = <?php echo $Size; ?>&nbsp;
FileType = <?php echo $Type;?>
<?php
		//$cmd = 'python '.ROOT . DS . DS. 'scripts' . DS .DS . 'mp3.py ' . '\'-f '.$Location.'\'';
		//exec($cmd, $result); 
?>


<?php 
	if(isset($ReturnCode))
	{
		echo 'seems there was a problem uploading : '. $ReturnCode;
	}

	if(isset($exsists))
	{
		echo 'That file already exsists... y u be trollin? ';
	}

	if(isset($InvalidFileType))
	{
		echo 'lol... invalid file type noob... ';
	}
?>


<form name="input" action="../Admin/submitMusicData" method="post">
<?php 
//echo $cmd;
?>
 <br/>
Name of Song: <input type="text" name="songName" value = "<?php echo $Upload;?>" /><br/>
New Artist: <input type="checkbox" name="option1" value="Milk" onClick=" switchToTextbox('artistID', 'artistSelect', 'artistName', new Array(<?php
	for($i = 0 ; $i < count($ArtistList) - 1; $i++)
	{
		echo '\''.$ArtistList[$i]['Artist']['artistName'] .'\',';
	}
	echo '\''.$ArtistList[count($ArtistList)-1]['Artist']['artistName'] .'\'))';
?>
"/>

<div id ="artistSelect">
<select name="artistName" id="artistID" onChange="updateAlbumList(this.value, 'albumID');">
<?php
	foreach( $ArtistList as $artist)
	{
		echo '<option value="' . $artist['Artist']['artistName'] . '">' . $artist['Artist']['artistName'] . '</option>';
  } ?>
</select> </div>

New Album: <input type="checkbox" name="option1" onClick=" switchToTextbox('albumID', 'albumSelect', 'albumName', new Array(''))"/>
<div id ="albumSelect">

<select name="albumName" id="albumID" >
</select> 
</div>

<input type="hidden" name="oldName" value= "<?php echo $Upload;?>"/>
<input type="submit" value="Submit" /><br/>
</form>
