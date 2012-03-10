

<div id="leftContainer">

<div id="searchBox">
<h4> Search</h4>
<form>
Artist Name: <input type="text" name="artistName"/> <BR/>
Song Name: <input type="text" name="songName"/>
<input type="submit" value="search" />
</form>
</div>

<div id="playlists">
<h4> playlists</h4>
<?php 

foreach ($playlists as $playList)
{
	echo '<div class="playlistEl"><a href="#" >'. $playList.'</a></div>';

}


?>

</div>


</div>


<?php

echo '<div id="ArtistList">';

foreach ($artists as &$artist)
{
	echo '<div id="movieElement">';
	echo '<h4>' . $artist[0]. '</h4>';
	echo '<p>' .$artist[1] . '</p>';
	echo '<p>' .$artist[2] . '</p>';
	
	echo'<form class="movForm" action="../Music/viewArtist" method="post">
		<input type="hidden" value="'.$artist[0].'" name="artist" />
		<input type="submit" value="play" />
	</form>';
	echo '</div>';
	
	echo '<br/>';
	
	echo '<br/>';
}
echo '</div>';