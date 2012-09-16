<?php

?>
<link rel="stylesheet" type="text/css" href="<?php echo PUBLIC_FOLDER;?>/css/TVViewEpisode.css">
<script type="text/javascript">

	function playMovie(agentIP, movieID)
	{
		sendAJAXRequest("../../TV/requestAgentPlayTV", new Array (agentIP,movieID),"replyDiv");
	}

</script>