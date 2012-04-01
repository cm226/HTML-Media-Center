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
	
	function createSeriesIfNecessary($Series)
	{	
		if(count($this->query("SELECT seriesName FROM Series WHERE seriesName = '" . $Series. "'")) == 0)
			{
				$createq = "insert into Series values('". $Series ."', 10, '2010', '')";
				$this->query($createq);
			}
	}
	
	function createSeasonIfNecessary($Series, $Season)
	{
		$seasonq = "SELECT seasonID FROM Season WHERE seriesName = '$Series' AND seriesNumber = $Season";
		$seasonRes = $this->query($seasonq);
		
		if(count($seasonRes) > 0)
			return $seasonRes;
		
		else
		{
			$addSeasonq = "INSERT INTO Season values('','$Series',$Season)";
			$addSeasonRes = $this->query($seasonq);
			
			$seasonRes = $this->query($seasonq);
			if(count($seasonRes) > 0)
				return $seasonRes;
			
			else
				echo 'problem adding series';
		}
	}
	
	function createEpisode($epName,
							$epLengh,
							$playCount,
							$seasonID,
							$epURL,
							$epNumber)
	{
		$epQueery = "INSERT INTO Episode Values('$epName',
									'$epLengh',
									$playCount,
									$seasonID,
									'$epURL',
									$epNumber)";
									
									
		$this->query($epQueery);
	
	}
}