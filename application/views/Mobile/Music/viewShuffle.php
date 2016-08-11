<script type="text/javascript">



function eventHook()
{
	allSongsPlayedEvnt.addHandler(refreshSongs);
}

function refreshSongs()
{
	window.location.reload();
}

function refreshIframe(artistName, albumName)
	{
		postwith('../Music/viewPlayer',{artist:artistName, album:albumName}, "player");
	}
	
	
	function populateIFrame () {
	var frm = document.getElementById("ArtistPoster");
	frm.submit();
	}

window.onload = function(){
//			eventHook();
			populateIFrame();
			}
	
</script>

<div id="page">
	<div id="player">
	<form id="ArtistPoster" hidden="true" action="../Music/viewPlayer/" method="post" target="player">
  <input type="submit" value="Do Stuff!" />
</form>

<iframe id="player" name="player"/>
	</div>
</div>
