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

<form name="input" action="../Admin/submitPictureData" method="post">
New Album: <input type="checkbox" onClick=" switchToTextbox('albumID','albumSelect','PicName',new Array(<?php
	for($i = 0 ; $i < count($albums) - 1; $i++)
	{
		echo '\''.$albums[$i]['PictureAlbum']['albumName'] .'\',';
	}
	echo '\''.$albums[count($albums)-1]['PictureAlbum']['albumName'] .'\'))';
?>
"/>
Series: <div id ="albumSelect">
<select name="Album" id="albumID">
<?php
	foreach( $albums as $album)
	{
		echo '<option value="' . $album['PictureAlbum']['albumName'] . '">' . $album['PictureAlbum']['albumName'] . '</option>';
  } ?>
</select> </div>
 <br/>
name: <input type="text" name="PicName" value="<?php echo $Upload; ?>"/>
<input type="hidden" name="oldName" value= "<?php echo $Upload;?>"/>
<input type="submit" value="Submit" /><br/>
</form>