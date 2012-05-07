<?php

echo '<div name="movieList">';

foreach ($movies as &$movie)
{
	echo '<div class="movieElement">';
	echo '<h4>' . $movie[0]. '</h4>';
	echo '<p>' .$movie[1] . '</p>';
	echo '<p>' .$movie[2] . '</p>';
	
	echo'<form class="movForm" action="../Movies/viewSingle" method="post">
		<input type="hidden" value="'.$movie[0].'" name="movie" />
		<input type="submit" value="play" />
	</form>';
	echo '</div>';
	
	echo '<br/>';
}
echo '</div>';