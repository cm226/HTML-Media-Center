
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

<style type="text/css">

#freeDiskSpace
{
	border: solid 2px #838383;
    border-radius: 3x;
	-moz-border-radius: 3px;
	-webkit-border-radius: 3px;
	height: 200px;
	

}

#harddrive
{
	width: 50%;
	margin-left: 25%;
	background-color: yellow;
	height: 40px;
}

#total
{
	width: <?php echo $usedPercentage; ?>%;
	background-color: red;
	float: left;
}

#free
{
width: <?php echo $percentage; ?>%;
background-color: blue;
float:right;
}

</style>

