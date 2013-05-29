<?php

foreach ($plugins as $plugin)
{
	?>
	<div class="collapableFolder">	
	<div class="collapsableFolderHeader">
		<h4 class="widgetHeader"><?php echo $plugin[0]; ?></h4>
	</div>
	
	<?php
		for($i =1; $i < count($plugin); $i++)
		{
			?>
			<div class="pluginHolder">
				<div class="plugin" onclick="window.location=' ../Plugin/pluginPage/<?php echo $plugin[$i];?>';">
					<h2 class="widgetHeader" ><?php echo $plugin[$i];?></h2>
				</div>
			</div>
			<?php
		}
	?>

	</div>
<?php
}

?>

