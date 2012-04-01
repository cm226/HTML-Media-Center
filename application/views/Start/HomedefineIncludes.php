
<link rel="stylesheet" type="text/css" href="../public/css/homeStyle.css">
<script type="text/javascript" src="../public/js/searchOvelayWindows.js"></script>
<script>

function movieSearch(){
	var thediv=document.getElementById('backgroundDisplay');
	var thedivTop=document.getElementById('MoviesTopBox');
	if(thediv.style.display == "none"){
		thediv.style.display = "";
		thedivTop.style.display = "";
		thedivTop.innerHTML = movieOverlay;

	}else{
		thediv.style.display = "none";
		thediv.innerHTML = '';
		thedivTop.style.display = "none";
		thedivTop.innerHTML = '';
		
	}
	return false;
}


function musicSearch ()
{
	var thediv=document.getElementById('backgroundDisplay');
	var thedivTop=document.getElementById('MusicTopBox');
	if(thediv.style.display == "none"){
		thediv.style.display = "";
		thedivTop.style.display = "";
		thedivTop.innerHTML = musicOverlay;

	}else{
		thediv.style.display = "none";
		thediv.innerHTML = '';
		thedivTop.style.display = "none";
		thedivTop.innerHTML = '';
		
	}
	return false;
}
</script>
