<script type="text/javascript">
	function refreshIframe(artistId, albumName)
	{
		console.log('../viewPlayer/'+artistId);
		postwith('../viewPlayer/'+artistId,{album:albumName}, "player");
	}
	
	
	function populateIFrame () {
	var frm = document.getElementById("ArtistPoster");
	frm.submit();
	}
	window.onload = populateIFrame;
</script>

<style>

</style>


<h3><?php echo $artistsName; ?> </h3>
<div id="songSelection">
<img src="../public/img/Music/icons/shuffle.png" height="50" width="50" />
<div id="albumList">
<h4> Albums </h4>
<?php 
foreach ($albums as $album)
{
	echo '<div class="album" onClick="refreshIframe(\'' . $artistID . '\', \''. $album['Album']['albumName'] .'\');">
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
				<p class="meta" >Rateing:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;'. $album['Album']['albumRating'] .'/10</p>
			</div>
		 </div>';
		 
		 

}

?>


</div>
</div>

<form id="ArtistPoster" hidden="true" action="../viewPlayer/<?php echo $artistID; ?>" method="post" target="player">
  <input type="submit" value="Do Stuff!" />
</form>

<iframe id="player" name="player" />



