<?php

define("PORT",45001);
function stopVideoStream($agentIP, $mediaName)
{
	$message = "STOP_VID_STREAM,"+$mediaName;
	$reply = sendAbstractMessage($agentIP,$message);
	
	
	if(count($reply) == 2)
	{
		if($replaySegments[0] == "STOP_STREAM_REPLY")
		{
			if($replaySegments[1] == "OK")
			{
				return 1;
			}
		}
	}
	return -1;
}


function pauseVideoStream($agentIP, $mediaName)
{
	$message = "PAUSE_VID_STREAM,"+$mediaName;
	$reply = sendAbstractMessage($agentIP, $message);
	
	if($reply == -1)
		return -1;
		
	if(count($reply) == 2)
	{
		if($replaySegments[0] == "PAUSE_STREAM_REPLY")
		{
			if($replaySegments[1] == "OK")
			{
				return 1;
			}
		}
	}
	
	return -1;
}


function playVideoStream($agentIP, $streamURL)
{
	$message = "PLAY_VID_STREAM,".$streamURL;
	
	$replaySegments = sendAbstractMessage($agentIP,$message);
	
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

function sendAbstractMessage($ip, $message)
{
	$reply = "";
	$fp = fsockopen($ip, constant("PORT"), $errno, $errstr, 30);
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
		
		return explode(",",$reply);
	}
	
	
}

?>