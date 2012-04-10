
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

	

}

#harddrive
{
	border: solid 1px #000000;
	width: 50%;
	margin-left: 25%;
	background-color: black;
	height: 20px;
}

#total
{
	width: <?php echo $usedPercentage; ?>%;
	background-image:url('../public/img/Home/usedGrad.png');
	background-repeat: repeat-x;
	float: left;
}

#free
{
width: <?php echo $percentage; ?>%;
	background-image:url('../public/img/Home/greyGard.png');
	background-repeat: repeat-x;
float:right;
}

</style>

