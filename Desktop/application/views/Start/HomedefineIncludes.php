
<link rel="stylesheet" type="text/css" href="../public/css/homeStyle.css">
<script type="text/javascript" src="../public/js/searchOvelayWindows.js"></script>
<script type="text/javascript" src="../public/js/Home.js"></script>

<style type="text/css">

#freeDiskSpace
{
	position: absolute;
	bottom: 0px;
	top: 30%;
	width:100px;
	margin-left: 20px;
}

#harddrive
{
	border: solid 1px #000000;
	height: 70%;
	position:relative;
	float:left;
	margin-top:25px;
	width:30px;
}

#total
{
	height: 100%; <?php //echo $usedPercentage; ?>%;
	background-color: 	#303030 ;
	float: left;
}

#free
{
	height: <?php echo $percentage; ?>%;
	position: absolute;
	bottom:0px;
	width: 95%;
	background-color:#808080 ;
	float:left;
}

</style>

