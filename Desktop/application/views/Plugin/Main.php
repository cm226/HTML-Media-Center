<?php

foreach ($plugins as $plugin)
{
	?>
	<div class="plugin" onClick="window.location=' ../Plugin/pluginPage/<?php echo $plugin;?>';">
	<h2><?php echo $plugin; ?></h2>
	</div>
<?php
}

?>