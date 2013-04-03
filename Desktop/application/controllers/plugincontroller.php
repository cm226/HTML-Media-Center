<?php
class PluginController extends Controller {

function Main()
{
	$this->set('plugins',$this->Plugin->getPluginList());		
}

function pluginPage($plugin)
{
	$this->set('page',$this->Plugin->getPluginPage($plugin));		
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
	
	$this->set('page',$this->Plugin->getPluginReply($callbackID,$contextElements));	
}


}
?>
