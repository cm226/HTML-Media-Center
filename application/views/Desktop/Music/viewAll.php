

<?php

echo '<div id="ArtistList">';
foreach ($artists as &$artist)
{
	echo '<a href="../Music/viewArtist/'.$artist['Artist']['artistID'].'">';
	echo '<div class="artistElement">';
	
	$safeName = str_replace(' ','.',$artist['Artist']['artistName']);
	$safeName = '../public/img/Music/Artists/' . $safeName;
	
	if(file_exists($safeName . '.png'))
		echo '<img src="'.$safeName . '.png" height="128" width="128">';
	else if (file_exists($safeName . '.jpg'))
		echo '<img src="'.$safeName . '.jpg" height="128" width="128">';
	else
		echo '<img src="../public/img/Music/Artists/default.png" height="128" width="128">';
		
	echo '<h4 class="ArtistName">' . $artist['Artist']['artistName']. '</h4>';
	echo '<p class="artistInfo"> Genra: ' .$artist['Artist']['genre'] . '</p>';
	echo '<p class="artistInfo">No. tracks: '. $artist['Artist']['artistRating'] .' Rateing: ' .$artist['Artist']['artistRating'] . '</p>';
	echo '</div>';
	echo '</a>';
	
}
echo '</div>';
