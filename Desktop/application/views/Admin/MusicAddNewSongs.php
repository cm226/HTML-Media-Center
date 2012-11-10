<div id="addSingleSong" class = "elementContainer">
<div class="header" >
	select the file: 
</div>

<form action="../Admin/uploadMusic" method="post" enctype="multipart/form-data">
<div id="mp3Files">
	<div class="mp3File">
		<label>mp3 file: </label>
		<input type="file" name="file0" id="file" />
		<lable>name:</lable>
		<input type="text" name="songName0"/>
		<lable>album:</lable>
		<select class="albumSelect" name="filealbum0" id="albumID">
		</select>
		<br />
	</div>
</div>
	<button type="button" onclick="addMp3Box();">Add another MP3</button>

	<div id="artistInfo">
		<select name="artistName" id="artistID" onChange="updateAllAlbumLists(this.value, 'albumSelect');">
		<?php
			foreach( $ArtistList as $artist)
			{
				echo '<option value="' . $artist['Artist']['artistID'] . '">' . $artist['Artist']['artistName'] . '</option>';
		  } ?>
		</select>
		
		<label>New Artist: </label>
		<input type="test" name="newArtist"/> 
	</div>

	<input type="submit" name="submit" value="Submit" />
</form>

</div>


