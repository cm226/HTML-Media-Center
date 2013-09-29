<?php

class RemoteController extends Controller
{
	function agentSelection()
	{
		$agent1 = array();
		$agent2 = array();

		$agent1[0] = "agent 1";
		$agent1[1] = 1;

		$agent2[0] = "agent 2";
		$agent2[1] = 2;

		$agents = array();
		$agents[0] = $agent1;
		$agents[1] = $agent2;

		$this->set('agents', $agents);
	}

	function controller($agentID)
	{
		$this->set('agentID',$agentID);
	}
}
