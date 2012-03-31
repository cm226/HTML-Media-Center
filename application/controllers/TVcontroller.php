<?php
class TVController extends Controller 
{

	function viewall($seriesName = '')
	{
		if($seriesName == '')
			$publicFolder = "../../public";
		else
		{
			$seasonArray = $this->TV->seasonNumbers($seriesName);
			$publicFolder = "../../";
			$this->set('seasons',$seasonArray);
			$this->set('seriesName',$seriesName);
			$episodeArray = array();
			
			foreach ($seasonArray as $season)
			{
				$episodeArray[$season['Season']['seriesNumber']] = $this->TV->seasonEpisodes($seriesName,$season['Season']['seriesNumber']);
			}
			
			$this->set('episodes',$episodeArray);
			
		}
		
		$this->set('publicFolder', $publicFolder);
		$this->set('seriesNames',$this->TV->seriesNames());

	}
	
	function viewEpisode($EpisodeName)
	{
		$this->set('URL',$this->TV->getEpisodeURL($EpisodeName));
	}
}