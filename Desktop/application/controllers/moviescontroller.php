<?php

class MoviesController extends Controller {
	
	function viewall()
	{
		$this->set('movies',$this->Movie->viewAll());
	}
	
	function viewSingle($movieID)
	{
		$movieEntry = $this->Movie->view($movieID);
		$movieURL = $movieEntry[0]['Movie']['movieURL'];
		$movieURL = str_replace(" ","%20",$movieURL);
		$this->set('movieURL',$movieURL);
	}
}
