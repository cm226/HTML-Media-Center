<?php

class IMDBrateing extends Model {
	
	function fetchIMDBrateing($movieName)
	{
		unset($result); 
		
		$cmd = ROOT . DS . DS. 'scripts' . DS .DS . 'IMDBRateingGetterDev.py ' . $movieName;
		exec($cmd, $result); 
		return $result;

	}
}
