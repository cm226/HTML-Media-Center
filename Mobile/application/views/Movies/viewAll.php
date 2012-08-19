<?php

echo '<div name="movieList">';

foreach ($movies as &$movie)
{
	?>
	<div class="movieElement" onClick="window.location = '../Movies/playMovie/<?php echo $movie['Movie']['movieID'] ?>';">
		<img class="movieImg" src="<?php echo PUBLIC_FOLDER.$movie['Movie']['thumbnailURL']; ?>"/>
		<div class="infoPanel">
			<h4><?php echo $movie['Movie']['movieName'];?></h4>
			<p><?php echo $movie['Movie']['movieLength']; ?> </p>
			<p><?php echo $movie['Movie']['movieGenre']; ?></p>
			<p><?php echo $movie['Movie']['movieIMDB']; ?></p>
		</div>
	</div>
	
	<br/>
	<?php
}

?>
</div>