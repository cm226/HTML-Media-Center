<?php 
	echo 'you are viewing: '. $albumName;
?>

<div class="pictureList">
	<?php 
		foreach ($pictureDetails as $picture)
		{
			echo '<img src="../'. $picture['Picture']['picURL']. '" height="100" width="100"/>';
		}
	?>
</div>
