
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
	width:70%;
	margin-left:30%;
		float:left;
		
}

#harddrive
{
	border: solid 1px #000000;
	width: 50%;
	position:relative;
	float:left;
	margin-top:25px;
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

