<link rel="stylesheet" type="text/css" href="<?php echo PUBLIC_FOLDER;?>/css/TVViewAll.css">
<script type="text/javascript">
var selectionMatrix = <?php
/*
$maxArraySize
$seasonsLength = count($seasons);
$seriesNamesLength = count($seriesNames);

if(isset($seasons))
{
	if($seriesNamesLength > $seasonsLength)
		$maxArraySize = $seriesNamesLength;
	else
		$maxArraySize = $seasonsLength;
}
else
{
	$maxArraySize = $seriesNamesLength;
}

echo '[';
foreach($i = 0; $i < $maxArraySize; $i++)
{
	echo '[';
	
	if($i < $seriesNamesLength)
		echo '["'.$seriesNames[$i]['Series']['seriesName'].'","seriesLink"], ';
	else 
		echo '["",""], ';
	
	if(isset($seasons))
	{
		if($i < $seasonsLength)
		{
			echo '["'.$seasons[$i]['Series']['seriesName'].'","seriesLink"], ';
		}
	}
	
	echo ']';

}
echo '];';
*/
?>
</script>

<style> 
body{
		background-image:url('<?php echo PUBLIC_FOLDER;?>/img/TV/bgPic.jpg');
		background-size:cover;
		background-repeat:no-repeat;
	}
</style>
