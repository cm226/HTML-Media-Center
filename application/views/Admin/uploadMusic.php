FileName = <?php echo $Location; ?>&nbsp;
FileSize = <?php echo $Size; ?>&nbsp;
FileType = <?php echo $Type;?>
<?php
		$cmd = 'python '.ROOT . DS . DS. 'scripts' . DS .DS . 'mp3.py ' . '\'-f '.$Location.'\'';
		exec($cmd, $result); 
?>
<form name="input" action="../Admin/submitMusicData" method="post">
<?php 
echo $cmd;
?>
 <br/>
Name of Song: <input type="text" name="eName" value = "<?php echo $Upload;?>" /><br/>
<input type="submit" value="Submit" /><br/>
</form>