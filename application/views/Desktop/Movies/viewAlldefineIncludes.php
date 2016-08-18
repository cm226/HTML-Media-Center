<link rel="stylesheet" type="text/css" href="<?php echo PUBLIC_FOLDER;?>/css/Desktop/movieViewAll.css" />

<script type="text/javascript">


$(document).ready(function()
{
	var count = $("#movieList").children().length;
	var artistListLen = (count/2) * 200;
	
	$("#movieList").css("width",artistListLen+"px")
    
	
	$("body").mousewheel(function(event, delta) {

      
	  var left = $("#content").scrollLeft();
	  var newval =  left- (delta*30);
	  $("#content").scrollLeft(newval );
      event.preventDefault();

   });

});

</script>
