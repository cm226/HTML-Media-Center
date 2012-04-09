<?php

class StartController extends Controller {
	
	function Home()
	{
		list($totalSpace, $freeSpace) = $this->Start->getFreeSpace();
		$this->set("total",$totalSpace);
		$this->set("free",$freeSpace);
	}
}
