<?php


class PluginController extends Controller {

function Main()
{
	$this->set('plugins',$this->Plugin->getPluginList());		
}

// can handle this wen mergin controllers by haveing 2 different methods in here pluginPage and mobilePluginPage
function mobilePluginPage($plugin)
{
	$this->set('page',$this->Plugin->getPluginPage($plugin, true));		
}

function pluginPage($plugin)
{
	$this->set('page',$this->Plugin->getPluginPage($plugin, false));		
}

function pluginInteraction()
{
	
	$contextElements = func_get_args();

	if(count($contextElements) < 2)
	{
		echo 'Error: bad ammount of arguments in context no callbackID';
		return;
	}
	
	$callbackID = array_shift($contextElements);
	if(!ctype_digit ($callbackID))
	{
		echo 'Error: bad callbackID not an uint : '.$callbackID ;
		return;
	}
	
	foreach( $_POST as $post_key => $post_val) {
	    if( is_array( $post_val) ) {
	        foreach( $post_val as $postvar_key => $postvar_val ) 
	        {
	            array_push($contextElements, $postvar_key. "=" . $postvar_val );
	        }
	    } else {
	        array_push($contextElements, $post_key . "=" . $post_val);
	    }
	}

	$this->set('page',$this->Plugin->getPluginReply($callbackID,$contextElements));	
}

function Status()
{
	$processedCatagorys = array();
	$statusData = $this->Plugin->getStatusData();
	$catagories = explode(',',$statusData);
	foreach($catagories as $catagory)
	{
		$catagoryEntrysStart = strpos($catagory, '{');
		$catagoryEntrysEnd = strpos($catagory, '}');

		if($catagoryEntrysStart and $catagoryEntrysEnd)
		{
			$catName = substr($catagory,0, $catagoryEntrysStart);
			$carVals = substr($catagory,$catagoryEntrysStart+1, $catagoryEntrysEnd - $catagoryEntrysStart -1);
			$allValls = explode('.',$carVals);
			$processedStatusValues = array();
			foreach($allValls as $val)
			{
				$nameStatus = explode(':',$val);
				$procVal = array();
				$procVal[0] = $nameStatus[0];
	
				if($nameStatus[1] == "1") $procVal[1] = true;
				else $procVal[1] = false;

				array_push($processedStatusValues, $procVal);
			}
			$processedCatagorys[$catName] =$processedStatusValues;
		}
		else
		{
		}
	}

	$this->set('processedCatagorys',$processedCatagorys);	

}


}
?>
