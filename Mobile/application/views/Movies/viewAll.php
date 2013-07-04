
<div id="movieList">
<ul data-role="listview" data-inset="true">

<?php
foreach ($movies as &$movie)
{
	?>
	<li><a href="../Movies/playMovie/<?php echo $movie['Movie']['movieID']; ?>">
	
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
	
	
	</a></li>
	<?php
}

?>

</ul>
</div>