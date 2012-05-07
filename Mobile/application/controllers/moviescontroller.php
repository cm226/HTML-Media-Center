<?php

class MoviesController extends Controller {
	
	function viewall()
	{
		$this->set('movies',$this->Movie->viewAll());
	}
	
	function viewSingle()
	{
		$this->set('movieURL',$this->Movie->view($_POST['movie']));
	}
}
