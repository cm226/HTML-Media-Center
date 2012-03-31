FileName = <?php echo $Location; ?>
FileSize = <?php echo $Size; ?>
FileType = <?php echo $Type;?>

<form name="input" action="../TV/submitTVData" method="post">
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
<input type="submit" value="Submit" /><br/>
</form>