

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
	echo '<div class="playlistEl"><a href="../Music/viewPlaylist/'. $playList['Playlist']['playlistName']. '" >'. $playList['Playlist']['playlistName'].'</a></div>';

}
?>

<form action="../Music/viewAll" method="POST">
	New Playlist: <input type="text" name="newPlaylist"/>
	<input type="submit" value="Add"/>
</form>
<form>
	<input type="submit" value="upload Itunes playlist file" />
</form>

</div>


</div>


<?php

echo '<div id="ArtistList">';
echo '<h3> Artists Selection </h3>';
foreach ($artists as &$artist)
{
	echo '<div class="artistElement" onclick="postwith(\'../Music/viewArtist\',{artist:\''.$artist['Artist']['artistID'].'\'})">';
	
	if(file_exists('../public/img/Music/Artists/' . $artist['Artist']['artistName'] . '.png'))
		echo '<img src="../public/img/Music/Artists/' . $artist['Artist']['artistName'] . '.png" height="128" width="128">';
	else
		echo '<img src="../public/img/Music/Artists/default.png" height="128" width="128">';
		
	echo '<h4 class="ArtistName">' . $artist['Artist']['artistName']. '</h4>';
	echo '<p class="artistInfo"> Genra: ' .$artist['Artist']['genre'] . '</p>';
	echo '<p class="artistInfo">No. tracks: '. $artist['Artist']['artistRating'] .' Rateing: ' .$artist['Artist']['artistRating'] . '</p>';
	echo '</div>';
	
}
echo '</div>';
