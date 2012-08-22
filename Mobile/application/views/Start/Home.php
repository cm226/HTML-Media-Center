<div id="freeDiskSpace"> 	
	<div  id="imgCont">
		<img src="../public/img/Home/harddrive100.png"/>
	</div>
	<div id="harddrive">
		
		<div id="total"> <?php echo $total;?></div>
		<div id="free">	<?php echo $free;?>	</div>

	</div>

</div>
<div id="metaPanel">
<div class="clock">
   <div id="Date"></div>
      <ul>
          <li id="hours"></li>
          <li id="point">:</li>
          <li id="min"></li>
          <li id="point">:</li>
          <li id="sec"></li>
      </ul>
</div>

</div>
<div id="menuSelection">

<div class="topTile" onclick="window.location = ('../Movies/viewAll')">
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

<div class="bottomTile" onClick="window.location = ('../Admin/Main')">
Admin
</div>
</div>
