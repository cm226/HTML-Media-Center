<?php

define("PORT",45001);

function playVideoStream($agentIP, $streamURL)
{
	$message = "PLAY_VID_STREAM,".$streamURL;
	$reply = "";
	$fp = fsockopen($agentIP, constant("PORT"), $errno, $errstr, 30);
	if (!$fp) 
	{
		return -1;
	}
	else 
	{
		fwrite($fp, $message);
		
		while (!feof($fp)) 
		{
			$reply .= fgets($fp, 128);
		}
		fclose($fp);
	}
	$replaySegments = explode(",",$reply);
	
	if(count($replaySegments) == 2)
	{
		if($replaySegments[0] == "PLAY_STREAM_REPLY")
		{
			if($replaySegments[1] == "OK")
			{
				return 1;
			}
		}
	
	}

	return -1;
}

?>