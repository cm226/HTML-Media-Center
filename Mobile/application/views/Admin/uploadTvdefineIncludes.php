<script>
	function switchToTextbox()
	{
		var inputElement = document.getElementById('seriesID');
		if(inputElement.getAttribute( "type" ) == "text")
		{
			var seriesBox = document.getElementById('seriesSelect');
			seriesBox.innerHTML = '<select name="Series" id="seriesID" >\
<?php
	foreach( $seriesList as $series)
	{
		echo '<option value="' . $series['Series']['seriesName'] . '">' . $series['Series']['seriesName'] . '</option>\\';
  } ?>
</select> ';
		}
		else
		{
			var seriesBox = document.getElementById('seriesSelect');
			seriesBox.innerHTML = '<input type="text" name="Series" id="seriesID"/> ';
		}
	}

</script>
