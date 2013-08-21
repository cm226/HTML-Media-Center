<link rel="stylesheet" type="text/css" href="<?php echo PUBLIC_FOLDER;?>/css/Desktop/musicViewAll.css"/>

<script type="text/javascript">


$(document).ready(function()
{
	var count = $("#ArtistList").children().length;
	var artistElementWidth = parseInt($("#ArtistList").children().first().css("width")) + 4; // + 4 is for the padding


	var numRows;
	if(window.matchMedia("(max-height: 400px)").matches)
		numRows = 1;
	else
	{
		if(window.matchMedia( "(min-height: 700px)").matches)
			numRows = 3;
		else
			numRows = 2;
	}

	var artistListLen = Math.ceil(count/numRows) * artistElementWidth;
	console.log(artistListLen);
	console.log("num Rows: "+numRows);

	$("#ArtistList").css("width",artistListLen+"px")
    
	
	$("body").mousewheel(function(event, delta) {

      
	  var left = $("#content").scrollLeft();
	  var newval =  left- (delta*30);
	  $("#content").scrollLeft(newval );
      event.preventDefault();

   });

});

</script>
