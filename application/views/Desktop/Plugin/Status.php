<?php

while ($catagory = current($processedCatagorys))
{
	?>
    
	<div class="Catagory">	
		<h2><?php echo key($processedCatagorys);?> </h2>
		
	</div>

<?php     next($processedCatagorys);
}

var_dump($processedCatagorys);

