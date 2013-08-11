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
	
	function viewEpisode($EpisodeID)
	{
		$this->set('URL',$this->TV->getEpisodeWithID($EpisodeID));
		$this->set('Agents',array(array("IP"=>"192.168.0.198","Location"=>"LivingRoom","Name"=>"TV")));
	}
	
	function requestAgentPlayTV($agentIP, $movieID)
	{
		$this->set('agentIP',$agentIP);
		$this->set('tv',$this->TV->getEpisodeWithID($movieID));
	}
}
