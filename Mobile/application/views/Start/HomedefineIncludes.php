
<link rel="stylesheet" type="text/css" href="../public/css/homeStyle.css">
<script type="text/javascript" src="../public/js/searchOvelayWindows.js"></script>
<script type="text/javascript" src="http://code.jquery.com/jquery-1.6.4.min.js"></script>
<script>

$(document).ready(function() {
// Create two variable with the names of the months and days in an array
var monthNames = [ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" ]; 
var dayNames= ["Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"]

// Create a newDate() object
var newDate = new Date();
// Extract the current date from Date object
newDate.setDate(newDate.getDate());
// Output the day, date, month and year   
$('#Date').html(dayNames[newDate.getDay()] + " " + newDate.getDate() + ' ' + monthNames[newDate.getMonth()] + ' ' + newDate.getFullYear());

setInterval( function() {
	// Create a newDate() object and extract the seconds of the current time on the visitor's
	var seconds = new Date().getSeconds();
	// Add a leading zero to seconds value
	$("#sec").html(( seconds < 10 ? "0" : "" ) + seconds);
	},1000);
	
setInterval( function() {
	// Create a newDate() object and extract the minutes of the current time on the visitor's
	var minutes = new Date().getMinutes();
	// Add a leading zero to the minutes value
	$("#min").html(( minutes < 10 ? "0" : "" ) + minutes);
    },1000);
	
setInterval( function() {
	// Create a newDate() object and extract the hours of the current time on the visitor's
	var hours = new Date().getHours();
	// Add a leading zero to the hours value
	$("#hours").html(( hours < 10 ? "0" : "" ) + hours);
    }, 1000);	
});


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

