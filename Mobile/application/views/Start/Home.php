<h2> Start </h2>

<div id="freeDiskSpace"> 	
	<div  id="imgCont">
		<img src="../public/img/Home/harddrive100.png"/>
	</div>
	<div id="harddrive">
		
		<div id="total"> <?php echo $total;?></div>
		<div id="free">	<?php echo $free;?>	</div>

	</div>

</div>

<div id="backgroundDisplay" style="display: none;"></div>
<div id="MoviesTopBox" class="topBox" style="display: none;"></div>
<div id="MusicTopBox" class="topBox" style="display: none;"></div>
<div id="PicturesTopBox" class="topBox" style="display: none;"></div>
<div id="menuSelection">


<div class="tile" onclick='return movieSearch();'>
Movie
</div>

<div class="tile" onclick="window.location = ('../Music/viewAll')">
Music
</div>

<div class="tile" onClick="window.location = ('../TV/viewAll')">
TV
</div>

<div class="tile" onClick="window.location = ('../Pictures/albums')">
Pictures
</div>

<div class="tile" onClick="window.location = ('../Admin/Main')">
Admin
</div>
</div>
