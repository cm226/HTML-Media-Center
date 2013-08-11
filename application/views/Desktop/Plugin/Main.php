<?php

foreach ($plugins as $plugin)
{
	?>
	<div class="collapableFolder">	
	<div class="collapsableFolderHeader">
		<h4 class="widgetHeader"><?php echo $plugin[0]; ?></h4>
	</div>
	<div class="pluginHolder">
	<?php
		for($i =1; $i < count($plugin); $i++)
		{
			?>
			
				<div class="plugin" onclick="window.location=' ../Plugin/pluginPage/<?php echo $plugin[$i];?>';">
					<h2 class="widgetHeader" ><?php echo $plugin[$i];?></h2>
				</div>
			
			<?php
		}
	?>
	</div>
	</div>
<?php
}

?>
<div id="addNewFolder">
	<h4 id="newFolderAddBttn">+</h4>

	<div id="newFolderName"> 
		<h3 class="widgetHeader">New Folder</h3>
		<input type="text" id="newFolderNameVal"> </input>
		<button id="newFolderAddBttnComplete"> OK </button>
	</div>

</div

