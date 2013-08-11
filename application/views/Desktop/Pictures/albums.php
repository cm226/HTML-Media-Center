<h3> my albums </h3>

<div id="albumContainer"> 
	<?php 
		foreach ($albums as $album)
		{
			echo '<div class="album" onClick=\'window.location="../Pictures/viewAlbum/' . $album['PictureAlbum']['albumName']. '" \'>';
			echo '<img src="'. PUBLIC_FOLDER . DS . 'img'. DS . 'Pictures' . DS .'AlbumIcon.png" height="150px" width="150px"/>';
			echo $album['PictureAlbum']['albumName'];
			echo '</div>';
		}
	?>	
</div>
