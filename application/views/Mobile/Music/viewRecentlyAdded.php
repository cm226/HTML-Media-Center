<script type="text/javascript">

	
	
	function populateIFrame () {
	var frm = document.getElementById("ArtistPoster");
	frm.submit();
	}
	window.onload = populateIFrame;
</script>
<style>
body {
margin: 0px;
}

#pageContent
{
	height:100%;
	width:100%;
	
	padding:0px;
	margin:0px;
}



#player
{
	float: left;
	width : 100%;
	height :100%;
	border: 0px;
	padding: 0px;
}

</style>


<form id="ArtistPoster" hidden="true" action="../Music/viewPlayer" method="post" target="player">
  <input type="Hidden" name = "recentlyAdded" value="0" />
  <input type="submit" value="Do Stuff!" />
</form>

<iframe id="player" />