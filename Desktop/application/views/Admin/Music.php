<div class="elementContainer" id="addSongs">
	<div class="header" onClick="window.location='../Admin/MusicAddNewSongs'; ">Add Songs</div>
</div>

<div id="imageUploads">
<div id="uploadArtistPic" class="elementContainer">
<div class="header">
upload Artist Pic
</div>

<form action="../Admin/uploadArtistPic" method="post"
enctype="multipart/form-data">

<select name="artistName" id="artistID">
<?php
	foreach( $ArtistList as $artist)
	{
		echo '<option value="' . $artist['Artist']['artistName'] . '">' . $artist['Artist']['artistName'] . '</option>';
  } ?>
</select>
<br/>
<label for="file">png file: </label>
<input type="file" name="image" id="file" /> 
<br />
<input type="submit" name="submit" value="Submit" />
</form>

</div>
</div>






