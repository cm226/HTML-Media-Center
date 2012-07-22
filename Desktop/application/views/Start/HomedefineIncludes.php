
<link rel="stylesheet" type="text/css" href="../public/css/homeStyle.css">
<script type="text/javascript" src="../public/js/searchOvelayWindows.js"></script>
<script type="text/javascript" src="../public/js/Home.js"></script>

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

