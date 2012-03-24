<?php
class TVController extends Controller 
{

	function viewall()
	{
		$this->set('seriesNames',$this->TV->seriesNames());
	}
}