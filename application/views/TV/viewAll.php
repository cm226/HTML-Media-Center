<?php

echo '<ul>';

foreach ($movies as &$movie)
{
	echo '<li><h4>' . $movie[0]. '</h4></li>';
	echo '<li>' .$movie[1] . '</li>';
	echo '<li>' .$movie[2] . '</li>';
	
	echo '<br/>';
}
echo '</ul>';