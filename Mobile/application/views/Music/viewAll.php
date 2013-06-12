
<?php

echo '<ul id="ArtistList" data-role="listview" >';
foreach ($artists as &$artist)
{

	echo ' <li>';
	echo '<a rel="external" href="../Music/viewArtist/'.$artist['Artist']['artistID'].'"> ';
	if(file_exists('../public/img/Music/Artists/' . $artist['Artist']['artistName'] . '.png'))
		echo '<img src="../public/img/Music/Artists/' . $artist['Artist']['artistName'] . '.png" height="128" width="128">';
	else
		echo '<img src="../public/img/Music/Artists/default.png" height="128" width="128">';
		
	echo '<h4 class="ArtistName">' . $artist['Artist']['artistName']. '</h4>';
	echo '<p class="artistInfo"> Genra: ' .$artist['Artist']['genre'] . '</p>';
	echo '<p class="artistInfo">No. tracks: '. $artist['Artist']['artistRating'] .' Rateing: ' .$artist['Artist']['artistRating'] . '</p>';
	echo '</a>';
	echo '</li>';
	
}
echo '</ul>';

?>

