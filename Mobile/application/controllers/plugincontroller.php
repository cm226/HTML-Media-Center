<?php
class PluginController extends Controller {

function Main()
{
	$this->set('plugins',$this->Plugin->getPluginList());		
}

function pluginPage()
{
	$this->set('page',$this->Plugin->getPluginList());		
}


}
?>
