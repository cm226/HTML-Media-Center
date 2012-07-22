
<div id="leftPanel" onclick="window.location = '<?php echo PUBLIC_FOLDER.'/../'; ?>';">

<div id="freeDiskSpace"> 	
	
	<div id="harddrive">
		
		<div id="total"> <?php echo $total;?></div>
		<div id="free">	<?php echo $free;?>	</div>

	</div>
	<div  id="imgCont">
		<img src="../public/img/Home/harddrive100.png"/>
	</div>

</div>
</div>

<div id="tilesWrapper">
<div id="tiles" >

<div id="moviesPerspective">
<div id="moviesTile" class="tile" onclick="window.location = ('../Movies/viewAll')">
Movies
</div>
</div>

<div class="centerTile">
<div id="musicTile" class="tile" onclick="window.location = ('../Music/viewAll')">
Music
</div>
</div>

<div id="TVPerspective">
<div id="TVTile" class="tile" onClick="window.location = ('../TV/viewAll')">
TV
</div>
</div>

<div id="moviesPerspective">
<div id="picturesTile" class="tile" onClick="window.location = ('../Pictures/albums')">
Pictures
</div>
</div>

<div class="centerTile">
<div id="adminTile" class="tile" onClick="window.location = ('../Admin/Main')">
Admin
</div>
</div>

</div>
</div>

<div id="spinningDisks">
<div id="outerDisk">
</div>
<div id="innerDisk">
</div>
</div>

