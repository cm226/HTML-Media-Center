

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
echo '<h3> Artists Selection </h3>';
foreach ($artists as &$artist)
{
	echo '<div class="artistElement" onclick="postwith(\'../Music/viewArtist\',{artist:\''.$artist[0].'\'})">';
	echo '<img src="../Public/img/Music/Artists/' . $artist[0] . '.png" height="128" width="128">';
	echo '<h4 class="ArtistName">' . $artist[0]. '</h4>';
	echo '<p class="artistInfo"> Genra: ' .$artist[1] . '</p>';
	echo '<p class="artistInfo">No. tracks: '. $artist[3] .' Rateing: ' .$artist[2] . '</p>';
	echo '</div>';
	
}
echo '</div>';