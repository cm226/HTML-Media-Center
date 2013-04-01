<?php

echo '<div id="movieList">';

foreach ($movies as &$movie)
{
	?>
	<div class="movieElement" onClick="window.location = '../Movies/playMovie/<?php echo $movie['Movie']['movieID'] ?>';">
	<img class="movieImg" src="
		<?php
			if(file_exists(PUBLIC_FOLDER."/img/Movie/Thumbs/".$movie['Movie']['thumbnailURL']) &&$movie['Movie']['thumbnailURL'] != '')
				echo PUBLIC_FOLDER."/img/Movie/Thumbs/".$movie['Movie']['thumbnailURL'];
			else
				echo PUBLIC_FOLDER."/img/Movie/Thumbs/default.png";
		?>
		"/>
		<div class="infoPanel">
			<div class="headline"><?php echo $movie['Movie']['movieName'];?></div>
		</div>
	</div>
	<?php
}

?>
</div>