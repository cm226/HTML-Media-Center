FileName = <?php echo $Location; ?>
FileSize = <?php echo $Size; ?>
FileType = <?php echo $Type;?>

<form name="input" action="../Admin/submitTVData" method="post">
New Series: <input type="checkbox" name="option1" value="Milk">
Series: <select name="Series">
<?php
	foreach( $seriesList as $series)
	{
		echo '<option value="' . $series['Series']['seriesName'] . '">' . $series['Series']['seriesName'] . '</option>';
  } ?>
</select>
 <br/>
Name of Episode: <input type="text" name="eName" value = "<?php echo $Upload;?>" /><br/>
Season: <input type="text" name="Season" /><br/>
Episode number: <input type="text" name="eNumber" /><br/>
<input type="hidden" name="oldName" value= "<?php echo $Upload;?>"/>
<input type="submit" value="Submit" /><br/>
</form>