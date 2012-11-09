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
}

</style>


<form id="ArtistPoster" hidden="true" action="../Music/viewPlayer" method="post" target="player">
  <input type="Hidden" name = "artist" value="<?php echo $artistID; ?>" />
  <input type="submit" value="Do Stuff!" />
</form>

<iframe id="player" />



