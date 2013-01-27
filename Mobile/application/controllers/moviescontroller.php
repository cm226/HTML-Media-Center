<?php

class MoviesController extends Controller {
	
	function viewall()
	{
		$this->set('movies',$this->Movie->viewAll());
	}
	
	function playMovie($MovieID)
	{
		$this->set('movie',$this->Movie->getMovieWithID($MovieID));
	}
	
	function requestAgentPlayMovie($agentIP, $movieID)
	{
		$this->set('agentIP',$agentIP);
		$this->set('movie',str_replace(" ", "\\ ", $this->Movie->getMovieWithID($movieID)));
	}

	function agentPoll($movieID)
	{
		$this->set('agents', $this->Movie->getVideoAgents());
		$this->set('movieID',$movieID);
	}
}
