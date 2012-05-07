<script>
	function switchToTextbox()
	{
		var inputElement = document.getElementById('albumID');
		if(inputElement.getAttribute( "type" ) == "text")
		{
			var albumBox = document.getElementById('albumSelect');
			albumBox.innerHTML = '<select name="Album" id="albumID" >\
<?php
	foreach( $albums as $album)
	{
		echo '<option value="' . $album['PictureAlbum']['albumName'] . '">' . $album['PictureAlbum']['albumName'] . '</option>\\';
  } ?>
</select> ';
		}
		else
		{
			var albumBox = document.getElementById('albumSelect');
			albumBox.innerHTML = '<input type="text" name="Album" id="albumID"/> ';
		}
	}

</script>
