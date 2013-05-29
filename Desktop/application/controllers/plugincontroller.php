<?php
class PluginController extends Controller
 {

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

function Upload()
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
	
	
$uploaddir = ROOT.DS.'tempUploads/Plugin/';

 
// The posted data, for reference
$file = $_POST['value'];
$name = $_POST['name'];
 
// Get the mime
$getMime = explode('.', $name);
$mime = end($getMime);
 
// Separate out the data
$data = explode(',', $file);
 
// Encode it correctly
$encodedData = str_replace(' ','+',$data[1]);
$decodedData = base64_decode($encodedData);
 
// You can use the name given, or create a random name.
// We will create a random name!
 
$randomName = substr_replace(sha1(microtime(true)), '', 12).'.'.$mime;
$tempFileName = $uploaddir.$randomName;
 
if(file_put_contents($tempFileName, $decodedData))
{
	$contextElements[2] = $tempFileName;
	 $this->set('page',$this->Plugin->getPluginReply($callbackID,$contextElements));	
}
else
{
    // Show an error message should something go wrong.
    $this->set('page',"not good, not goot at all...");	
}


	
}

}
?>
