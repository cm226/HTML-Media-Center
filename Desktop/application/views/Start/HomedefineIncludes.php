
<link rel="stylesheet" type="text/css" href="../public/css/homeStyle.css">
<script type="text/javascript" src="../public/js/searchOvelayWindows.js"></script>
<script>

function slideIt()
{
	var slidingDiv = document.getElementById("d1");
	var stopPosition = 50;
	
	if (parseInt(slidingDiv.style.left) < stopPosition )
	{
		slidingDiv.style.left = parseInt(slidingDiv.style.left) + 2 + "px";
		setTimeout(slideIt, 1);
	}
}


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
	position: absolute;
	bottom: 0px;
	top: 30%;
	height:100%;
	width:100px;
	margin-left: 20px;
}

#harddrive
{
	border: solid 1px #000000;
	height: 50%;
	position:relative;
	float:left;
	margin-top:25px;
	width:30px;
}

#total
{
	height: <?php echo $usedPercentage; ?>%;
	background-image:url('../public/img/Home/usedGrad.png');
	background-repeat: repeat-Y;
	float: left;
}

#free
{
height: <?php echo $percentage; ?>%;
	background-image:url('../public/img/Home/greyGard.png');
	background-repeat: repeat-y;
float:left;
}

</style>

