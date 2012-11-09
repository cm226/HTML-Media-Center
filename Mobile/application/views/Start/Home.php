<div id="topMetaHolder" >
	<div class="clearfix">
		<div id="remoteHolder" onclick="window.location = '../Shared/RemoteControl';">
			<img src="<?php echo PUBLIC_FOLDER; ?>/img/Home/remote-Icon.png" />
		</div>
		<div id="dateHolder">
		   <div id="Date"></div>
			  <ul>
				  <li id="hours"></li>
				  <li id="point">:</li>
				  <li id="min"></li>
			  </ul>
		</div>
	</div>
</div>

<div id="menuSelection">

<div class="tile" onclick="window.location = ('../Movies/viewAll')">
Movie
</div>

<div class="tile" onclick="window.location = ('../Music/viewAll')">
<p>Music</p>
</div>

<div class="tile" onClick="window.location = ('../TV/viewAll')">
<p>TV</p>
</div>

<div class="tile" onClick="window.location = ('../Pictures/albums')">
<p>Pictures</p>
</div>


<div class="tile">
<div class="sharedTitleLeft"  onClick="window.location = ('../Admin/Main')">
<p>Admin</p>
</div>
<div class="sharedTitleRight"  onClick="window.location = ('../Plugin/Main')">
<p>Plugins</p>
</div>
</div>

</div>
