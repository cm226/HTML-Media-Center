<div id="currentInPlaylist">
	<div>
		<h2> <?php echo $playlistName; ?> </h2>
		<div id="playButtn"> playall </div>
	</div>

	<div id="songs">
		<?php 
			foreach ($songs as $song)
			{
				echo '<div class="song">';
				echo '<h4>'.$song['Song']['songName'].'</h4>';
				echo '<div class="songLength">'.$song['Song']['songLength'].'</div>';
			}
		?>
	</div>
</div>

<div id="add">
	<div> 
		<h4>add Songs</h4>
	</div>

	<form action="" method="post">
		Search: <input type="text" name="search"/>
		<input type="submit" value="Search" />
	</form>
</div>
