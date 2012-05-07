<?php
	if(!isset($Location))
	{
		echo 'There was a problem uploadin the file.. most likly that its too big? is it over 5 Gb? ';
	}

	if(isset($ReturnCode))
	{
		echo 'there was an error with the file: '. $ReturnCode;
	}

	if(isset($InvalidFileType) && $InvalidFileType == true)
	{
		echo 'the file type is invalid';
	}
	
	if(isset($exsists) && $exsists == true)
	{
		echo 'the file apready exsists...';
	}
?>

FileName = <?php echo $Location; ?>
FileSize = <?php echo $Size; ?>
FileType = <?php echo $Type;?>

<form name="input" action="../Admin/submitTVData" method="post">
New Series: <input type="checkbox" name="option1" value="Milk" onClick=" switchToTextbox('seriesID','seriesSelect','Series');">
Series: <div id ="seriesSelect">
<select name="Series" id="seriesID">
<?php
	foreach( $seriesList as $series)
	{
		echo '<option value="' . $series['Series']['seriesName'] . '">' . $series['Series']['seriesName'] . '</option>';
  } ?>
</select> </div>
 <br/>
Name of Episode: <input type="text" name="eName" value = "<?php echo $Upload;?>" /><br/>
Season: <input type="text" name="Season" /><br/>
Episode number: <input type="text" name="eNumber" /><br/>
<input type="hidden" name="oldName" value= "<?php echo $Upload;?>"/>
<input type="submit" value="Submit" /><br/>
</form>
