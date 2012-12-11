<?php

foreach ($plugins as $plugin)
{
	?>
	<div class="plugin" onClick=" ../Plugin/pluginPage/<?php echo $plugin;?>">
	<?php echo $plugin; ?>
	</div>
<?php
}

?>
