<?php

class StartController extends Controller {
	
	function Home()
	{
		list($totalSpace, $freeSpace) = $this->Start->getFreeSpace();
		$this->set("total",round($totalSpace , 2));
		$this->set("free", round($freeSpace,2));
		$this->set("percentage", ($freeSpace/$totalSpace)*100);
		$this->set("usedPercentage", ((($totalSpace - $freeSpace)/$totalSpace)*100));
	}
}
