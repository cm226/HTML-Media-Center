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
Name of Song: <input type="text" name="songName" value = "<?php echo $Upload;?>" /><br/>
Artist: <input type="text" name="artistName" value = "NickleBack" /><br/>
Album: <input type="text" name="albumName" value = "Here And Now" /><br/>
<input type="hidden" name="oldName" value= "<?php echo $Upload;?>"/>
<input type="submit" value="Submit" /><br/>
</form>
