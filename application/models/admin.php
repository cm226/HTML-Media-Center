<?php

class Admin extends Model
{
	function seriseList()
	{
		$seriseListQ = "SELECT seriesName FROM Series";
		$seriesRes = $this->query($seriseListQ);
		return $seriesRes;
	}
	
	function seasonList($seriesName)
	{
		$seriesNumbersQ = "SELECT seriesNumber FROM Season WHERE seriesName = '". $seriesName ."'";
		$seriesNumbersRes = $this->query($seriesNumbersQ);
		return $seriesNumbersRes;
	}
}