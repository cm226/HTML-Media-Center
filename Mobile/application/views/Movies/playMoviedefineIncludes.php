<link rel="stylesheet" type="text/css" href="<?php echo PUBLIC_FOLDER;?>/css/MoviesplayMovie.css">

<script type="text/javascript">

	function playMovie(agentIP, movieID)
	{
		sendAJAXRequest("../../Movies/requestAgentPlayMovie", new Array (agentIP,movieID),"replyDiv");
	}

</script>