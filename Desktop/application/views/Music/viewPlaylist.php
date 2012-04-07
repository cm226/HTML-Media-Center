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
				echo '<div class="songh"> <p>'.$song['Song']['songName'].'</p></div>';
				echo '<div class="songLength">'.$song['Song']['songLength'].'</div>';
				echo '</div>';
			}
		?>
	</div>
</div>

<div id="add">
	<div> 
		<h4>add Songs</h4>
	</div>

	<form action="../../Music/viewPlaylist/<?php echo $playlistName; ?>" method="post">
		Search: <input type="text" name="search"/>
		<input type="submit" value="Search" />
	</form>

	<div>
		<form action="../../Music/viewPlaylist/<?php echo $playlistName; ?>" method="post">
		<?php 
			if(isset($searchResults)) // this can be made mutch better with AJAX later but cba.... just now
			{
				$count = 0;
				foreach ($searchResults as $result)
				{	
					$count ++;
					echo '<div class="song">';
					echo '<input type="checkbox" name="res'.$count.'"/>';
					echo $result['Song']['songName'];
					echo '<input type="hidden" name="resURL' . $count. '" value="' . $result['Song']['songURL']. '"/>'; // its a gd thing this isent public otherwise this woul be bad
					echo '</div>';
				}
			}
		?>
		<input type="submit" value="add"/>
		</form>
	</div>
</div>
