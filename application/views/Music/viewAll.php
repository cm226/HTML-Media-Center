<?php

echo '<div name="ArtistList">';

foreach ($artists as &$artist)
{
	echo '<div class="movieElement">';
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