<h3> my albums </h3>

<div id="albumContainer"> 
	<?php 
		foreach ($albums as $album)
		{
			echo '<div class="album" onClick=\'window.location="../Pictures/viewAlbum/' . $album['PictureAlbum']['albumName']. '" \'>';
			echo $album['PictureAlbum']['albumName'];
			echo '</div>';
		}
	?>	
</div>
