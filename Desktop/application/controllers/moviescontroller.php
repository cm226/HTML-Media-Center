<?php

class MoviesController extends Controller {
	
	function viewall()
	{
		$this->set('movies',$this->Movie->viewAll());
	}
	
	function viewSingle($movieID)
	{
		$this->set('movieURL',$this->Movie->view($movieID));
	}
}
