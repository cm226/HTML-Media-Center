
<?php

echo '<div id="movieList">';
$i = 0;
$numOfMovies = count($movies)-1;
while(true)
{
	if($i %2 == 0 and $i > $numOfMovies)
		$i = 1;
	else if($i %2 != 0 and $i > $numOfMovies)
		break;
	
	$movie = $movies[$i];
	?>
	<div class="movieElement" onClick="window.location = '../Movies/viewSingle/<?php echo $movie['Movie']['movieID'] ?>';">
	<img class="movieImg" src="<?php
			$safeThumbURL = str_replace(' ','.',$movie['Movie']['thumbnailURL']);
			$safeThumbURL = str_replace('/','.',$safeThumbURL);
			$safeThumbURL = str_replace('\\','.',$safeThumbURL);
			
			if(file_exists(PUBLIC_FOLDER."/img/Movie/Thumbs/".$safeThumbURL) && $movie['Movie']['thumbnailURL'] != '')
				echo PUBLIC_FOLDER."/img/Movie/Thumbs/".$safeThumbURL."\" />";
			else
			{
				echo PUBLIC_FOLDER."/img/Movie/Thumbs/default.png\" />";	
				?>
					<div class="infoPanel">
						<div class="headline"><?php echo $movie['Movie']['movieName'];?></div>
					</div>
					
			<?php
			}
			
		?>
	</div>
	<?php
	
	$i+=2;
}
echo '</div>';