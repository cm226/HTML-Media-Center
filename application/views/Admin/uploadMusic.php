FileName = <?php echo $Location; ?>&nbsp;
FileSize = <?php echo $Size; ?>&nbsp;
FileType = <?php echo $Type;?>

<form name="input" action="../Admin/submitMusicData" method="post">

 <br/>
Name of Song: <input type="text" name="eName" value = "<?php echo $Upload;?>" /><br/>
<input type="submit" value="Submit" /><br/>
</form>