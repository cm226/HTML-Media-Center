<link rel="stylesheet" type="text/css" href="<?php echo PUBLIC_FOLDER;?>/css/Desktop/musicViewAll.css"/>

<script type="text/javascript">


$(document).ready(function()
{
	var count = $("#ArtistList").children().length;
	var artistListLen = (count/3) * 149;
	
	$("#ArtistList").css("width",artistListLen+"px")
    
	
	$("body").mousewheel(function(event, delta) {

      
	  var left = $("#content").scrollLeft();
	  var newval =  left- (delta*30);
	  $("#content").scrollLeft(newval );
      event.preventDefault();

   });

});

</script>
