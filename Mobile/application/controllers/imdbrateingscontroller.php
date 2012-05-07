<?php

class IMDBrateingsController extends Controller {

	function getIMDB() {
		$movie = $_POST['movie'];
		$this->set('movieName',$movie);
		$this->set('rateing',$this->IMDBrateing->fetchIMDBrateing($movie));
	}
	
	function view()
	{
	
	}
}
