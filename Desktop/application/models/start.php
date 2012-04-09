<?php

class start extends Model {

	function getFreeSpace()
	{
		$freeTotal = array(disk_total_space("/") /1024 /1204 /1024
				  ,disk_free_space("/")  /1024 /1024 /1024); 
		return $freeTotal;
	}
	
}
