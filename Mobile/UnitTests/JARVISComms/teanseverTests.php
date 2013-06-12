<?php

require '../../../Desktop/scripts/JARVISCOMS/Transever.php';

class teanseverTests extends PHPUnit_Framework_TestCase
{

	private function startSenderScript($scriptName)
	{
		// python script to connect and send messages to the cocket (hack due to php not haveing multythreading)
		$cmdWIN = 'python '.$scriptName;
		#$cmdUNIX = 'python shortmsgSender.py &';
		#$pid = shell_exec($cmdWIN);
		
		#windows only code
		$shell = new COM("WScript.Shell");
		$shell->run($cmdWIN, 0, false);
	}

	public function testRecvMessage()
    {
		$this->startSenderScript("shortmsgSender.py");
	
		$trans = new Transever();
		$msg = $trans->readReply();
		

		$this->assertEquals("world",$msg);
	}
	
	public function testRecvLargeMessage()
    {
		$this->startSenderScript("largemsgSender.py");
		
		$trans = new Transever(45002);
		$msg = $trans->readReply();
		$longMsg = str_repeat("a", 3000);
		
		$this->assertEquals($longMsg,$msg);
		
	}
	
}
	
?>