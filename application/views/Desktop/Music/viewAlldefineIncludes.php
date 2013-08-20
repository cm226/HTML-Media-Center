<link rel="stylesheet" type="text/css" href="<?php echo PUBLIC_FOLDER;?>/css/Desktop/musicViewAll.css"/>

<script type="text/javascript">


$(document).ready(function()
{
	var count = $("#ArtistList").children().length;
	var artistElementWidth = parseInt($("#ArtistList").children().first().css("width")) + 4; // + 4 is for the padding
	
	var numRows = 1;
	if(window.matchMedia( "(min-height: 700px)").matches)
		numRows = 3;
	else if(window.matchMedia( "(min-height: 500px)").matches)
		numRows = 2;
	
	console.log(numRows);
	var artistListLen = (count/numRows) * artistElementWidth;
	
	$("#ArtistList").css("width",artistListLen+"px")
    
	
	$("body").mousewheel(function(event, delta) {

      
	  var left = $("#content").scrollLeft();
	  var newval =  left- (delta*30);
	  $("#content").scrollLeft(newval );
      event.preventDefault();

   });

});

</script>
