<?php

class MoviesController extends Controller {
	
	function viewall()
	{
		$this->set('movies',$this->Movie->viewAll());
	}
}
