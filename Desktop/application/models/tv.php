<?php

class Tv extends Model {
	
	function seriesNames()
	{
		$seriesNamesq = "SELECT seriesName FROM Series";
		$seriesNameRes = $this->query($seriesNamesq);
		return $seriesNameRes;
	}
	
	function seasonNumbers($series)
	{
		$seasonNumbersq = "SELECT DISTINCT 
									seriesNumber
     						FROM Season
							WHERE
								seriesName = '" . $series . "'";
		$seasonNumbersRes = $this->query($seasonNumbersq);
		return $seasonNumbersRes;
	}
	
	function seasonEpisodes ($series,$season)
	{
		$seasonEpisodesq = "SELECT
								episodeNumber,
								episodeName,
								episodeLength,
								episodePlayCount
						  FROM Episode,
							   Season
						  WHERE Season.seriesName = '" . $series . "'
							AND Episode.seasonID = Season.seasonID
							AND seriesNumber = " . $season . "";
							
		$seasonEpisodesRes = $this->query($seasonEpisodesq);
		return $seasonEpisodesRes;
	}
	
	function getEpisodeURL($episodeName)
	{
		
		$urlQueery = 'SELECT filePath FROM Episode WHERE episodeName = "' . $episodeName. '"';
		
		echo $urlQueery;
		
		$urlResult = $this->query($urlQueery);
		return $urlResult;
	}
}
