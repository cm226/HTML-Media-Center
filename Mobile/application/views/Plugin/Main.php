<?php

foreach ($plugins as $plugin)
{
	?>
	<div class="plugin" onClick="window.location=' ../Plugin/pluginPage/<?php echo $plugin;?>';">
	<?php echo $plugin; ?>
	</div>
<?php
}

?>
