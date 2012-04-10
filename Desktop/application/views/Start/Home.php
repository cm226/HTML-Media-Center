<h2> Start </h2>
<div id="freeDiskSpace"> 	
<img src="../Public/img/Home/harddrive100.png"/>

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
<ul>
<li><a href="#" onclick='return movieSearch();'>Movies</a></li>
<li><a href="#" onclick='return musicSearch();'>Music</a></li>
<li><a href="../TV/viewAll">TV</a></li>
<li><a href="../Pictures/albums">Pictures</a></li>
<li><a href="../Admin/Main">Admin</a></li>
</ul>
</div>
