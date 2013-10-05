<?php

while ($catagory = current($processedCatagorys))
{
	?>
    
	<div class="Catagory">	
		<h2><?php echo key($processedCatagorys);?> </h2>
		<div class="catagoryBreakdown">
		<ul>
		<?php
		foreach($catagory as $catagoryStatusBreakdown)
		{
			if($catagoryStatusBreakdown[1])
				echo "<li style=\"background-color:green;\">";
			else
				echo "<li style=\"background-color:red;\">";

			echo $catagoryStatusBreakdown[0] . "</li>";
		}
		?>
		</ul>
		</div>
		
	</div>

<?php     next($processedCatagorys);
}

