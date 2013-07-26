<ul data-role="listview" data-inset="true">
<?php

foreach ($plugins as $plugin)
{
	
	for($i =1; $i < count($plugin); $i++)
		{
			?>
				<li><a rel="external" href="../Plugin/mobilePluginPage/<?php echo $plugin[$i];?>"><?php echo $plugin[$i];?></a></li>
			<?php
		}
}

?>
</ul>
