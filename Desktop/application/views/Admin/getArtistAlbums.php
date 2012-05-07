
<select>
<?php 
	foreach ($Albums as $album)
	{
		echo '<option value="' . $album['Album']['albumName'] . '">' . $album['Album']['albumName'] . '</option>';
	}
?>
</select>
