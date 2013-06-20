
<div id="leftGradient"></div>
<div id="rightGradient"></div>
<?php



echo '<div id="movieList">';

foreach ($movies as &$movie)
{
	?>
	<div class="movieElement" onClick="window.location = '../Movies/viewSingle/<?php echo $movie['Movie']['movieID'] ?>';">
	<img class="movieImg" src="<?php
			$safeThumbURL = str_replace(' ','.',$movie['Movie']['thumbnailURL']);
			$safeThumbURL = str_replace('/','.',$safeThumbURL);
			$safeThumbURL = str_replace('\\','.',$safeThumbURL);
			
			if(file_exists(PUBLIC_FOLDER."/img/Movie/Thumbs/".$safeThumbURL) && $movie['Movie']['thumbnailURL'] != '')
				echo PUBLIC_FOLDER."/img/Movie/Thumbs/".$safeThumbURL;
			else
				echo PUBLIC_FOLDER."/img/Movie/Thumbs/default.png";
		?>"/>
		<div class="infoPanel">
			<div class="headline"><?php echo $movie['Movie']['movieName'];?></div>
		</div>
	</div>
	<?php
}
echo '</div>';