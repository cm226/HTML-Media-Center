<script type="text/javascript">

	function playMovie(agentIP, movieID)
	{
		sendAJAXRequest("../../Movies/requestAgentPlayMovie", new Array (agentIP,movieID),"replyDiv");
	}

</script>