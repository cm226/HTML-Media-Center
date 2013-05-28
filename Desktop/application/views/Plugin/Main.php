<?php

foreach ($plugins as $plugin)
{
	?>
	<div class="plugin" onClick="window.location=' ../Plugin/pluginPage/<?php echo $plugin;?>';">
	<h2 class="widgetHeader"><?php echo $plugin; ?></h2>
	</div>
<?php
}

?>
