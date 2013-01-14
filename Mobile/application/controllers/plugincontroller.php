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


}
?>
