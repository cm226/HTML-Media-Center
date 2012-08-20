<?php

echo '<div name="movieList">';

foreach ($movies as &$movie)
{
	?>
	<div class="movieElement" onClick="window.location = '../Movies/playMovie/<?php echo $movie['Movie']['movieID'] ?>';">
		<img class="movieImg" src="<?php echo PUBLIC_FOLDER.$movie['Movie']['thumbnailURL']; ?>"/>
		<div class="infoPanel">
			<table>
			<tr><td>
			<h4><?php echo $movie['Movie']['movieName'];?></h4></td>
			<td><?php echo $movie['Movie']['movieLength']; ?> 
			<?php echo $movie['Movie']['movieGenre']; ?>
			<?php echo $movie['Movie']['movieIMDB']; ?></td></tr>
			</table>
		</div>
	</div>
	
	<br/>
	<?php
}

?>
</div>