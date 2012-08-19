<div id="selectedMovie">
	<h2><?php echo $movie[0]['Movie']['movieName'];?></h2>
	<img src="<?php echo PUBLIC_FOLDER.$movie[0]['Movie']['thumbnailURL'];?>">
	<?php echo '<h4>' . $movie[0]['Movie']['movieName']. '</h4>';
	echo '<p>' .$movie[0]['Movie']['movieLength'] . '</p>';
	echo '<p>' .$movie[0]['Movie']['movieGenre'] . '</p>';
	echo '<p>' .$movie[0]['Movie']['movieIMDB'] . '</p>';?>
</div>

<div =id="agents">
<h2> avalable Agents </h2>
<?php 
	foreach ($agents as $agent)
	{
		?>
		<div class="agent" onClick="playMovie(<?php echo "'".$agent["IP"]."', '".$movie[0]['Movie']['movieID']."'"?>);" >
			<p>location: <?php echo $agent["Location"];?></p>
			<p>name: <?php echo $agent["Name"];?></p>
		</div>
		<?php
		
	}
?>

<div id="replyDiv">
</div>

</div>