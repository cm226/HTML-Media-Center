
<link rel="stylesheet" type="text/css" href="../public/css/homeStyle.css">

<script>
function clicker(){
	var thediv=document.getElementById('displaybox');
	var thedivTop=document.getElementById('displayboxTop');
	if(thediv.style.display == "none"){
		thediv.style.display = "";
		thedivTop.style.display = "";
		//thediv.innerHTML = "<table id=\"innerTable\"width='70%' height='70%'><tr><td align='center' valign='middle' width='100%' height='100%'><br><br><a href='#' onclick='return clicker();'>CLOSE WINDOW</a></td></tr></table>";
		thedivTop.innerHTML = "<div id=\"innerTable\">\
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
	<a href='#' onclick='return clicker();'><- back</a>\
</div>\
</div>";

	}else{
		thediv.style.display = "none";
		thediv.innerHTML = '';
		thedivTop.style.display = "none";
		thedivTop.innerHTML = '';
		
	}
	return false;
}
</script>