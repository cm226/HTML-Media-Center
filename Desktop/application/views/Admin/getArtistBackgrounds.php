<?php

	foreach ($images as $result)
		echo '<img height="100" width="100" src="'.$result->{"url"}.'" onClick="setArtistImage(\''.$result->{"url"}.'\')" />'; 


