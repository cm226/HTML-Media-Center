var movieOverlay = "<div id=\"innerTable\">\
<h4>Enter Movie Criteria:</h4>\
<form action=\"../Movies/viewAll\" method=\"post\">\
    Movie Name: <input type=\"text\" name=\"movieName\" />\
    Genra: <input type=\"text\" name=\"genra\" />\
    IMDB: <select> \
            <option value=\"1\"></option>\
            <option value=\"2\"></option>\
            <option value=\"3\"></option>\
            <option value=\"4\"></option>\
            <option value=\"5\"></option>\
          </select>\
    Length: <input type=\"text\" name=\"length\" />\
    <input type=\"submit\" value=\"search\" /> \
</form>\
<div id=\"backLink\">\
	<a href='#' onclick='return movieSearch();'><- back</a>\
</div>\
</div>";


var musicOverlay = "<div id=\"innerTable\">\
<h4>Enter Music Criteria:</h4>\
<form action=\"../Music/viewAll\" method=\"post\">\
    Artist Name: <input type=\"text\" name=\"artist\" /><br/>\
    Song Name: <input type=\"text\" name=\"songName\" /><br/>\
    <input type=\"submit\" value=\"search\" /> \
</form>\
<a href=\"../Music/viewAll\">view all</a>\
<div id=\"backLink\">\
	<a href='#' onclick='return musicSearch();'><- back</a>\
</div>\
</div>";