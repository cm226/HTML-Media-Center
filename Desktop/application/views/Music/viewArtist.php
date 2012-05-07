<script type="text/javascript">
	function refreshIframe(artistName, albumName)
	{
		postwith('../Music/viewPlayer',{artist:artistName, album:albumName}, "player");
	}
	
	
	function populateIFrame () {
	var frm = document.getElementById("ArtistPoster");
	frm.submit();
	}
	window.onload = populateIFrame;
</script>

<style>
body
{
	background-image: url('../img/Music/Artists/<?php echo $artistsName;?>BG.png');
	background-size: 90% auto;
	background-position: 25% 0%;
	background-repeat:no-repeat;
	background-color:#000000;
}

</style>


<h3><?php echo $artistsName; ?> </h3>
<div id="songSelection">
<img src="../public/img/Music/icons/shuffle.png" height="50" width="50" />
<div id="albumList">
<h4> Albums </h4>
<?php 
foreach ($albums as $album)
{
	echo '<div class="album" onClick="refreshIframe(\'' . $artistsName . '\', \''. $album['Album']['albumName'] .'\');">
			<div class="imgCont">
				<img ';
if (file_exists('../public/img/Music/Albums/' . $album['Album']['albumName'] .'.png')) 
{
    echo 'src="../public/img/Music/Albums/' . $album['Album']['albumName'] .'.png "';
} else {
     echo 'src="../public/img/Music/Albums/default.png "';
}
				
	echo ' height="70" width="70"\>
			</div>
			<div class="metaCont">'
					. $album['Album']['albumName'] . 
				'<p class="meta" >'. $album['Album']['year'] .'</p>
				<p class="meta" >Track Count: '. $album['']['trackCount'] .'</p>
				<p class="meta" >Rateing:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;'. $album['Album']['albumRating'] .'/10</p>
			</div>
		 </div>';
		 
		 

}

?>


</div>
</div>

<form id="ArtistPoster" hidden="true" action="../Music/viewPlayer" method="post" target="player">
  <input type="Hidden" name = "artist" value="<?php echo $artistsName; ?>" />
  <input type="submit" value="Do Stuff!" />
</form>

<iframe id="player" />



