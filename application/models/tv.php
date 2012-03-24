<?php

class Tv extends Model {
	
	function seriesNames()
	{
		$seriesNames = array( "TrueBlood",
								"Supernatural",
								"The Walking Dead",
								"4400"
								);
								
		return $seriesNames;
	}
}
