<script type="text/javascript">

window.onload = eventHook;

function eventHook()
{
	allSongsPlayedEvnt.addHandler(refreshSongs);
	currentSong=-1;
	playNext();
}

function refreshSongs()
{
	window.location.reload();
}

</script>

<div id="page">
	<div id="player">
	<?php include 'viewPlayer.php'; ?>
	</div>
</div>