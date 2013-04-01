<div id="selectedMovie">
	
	<img class="movieImg" src="
		<?php
			if(file_exists("../public/img/Movie/Thumbs/".$movie[0]['Movie']['thumbnailURL']	) &&$movie[0]['Movie']['thumbnailURL'] != '')
				echo "../../public/img/Movie/Thumbs/".$movie[0]['Movie']['thumbnailURL'];
			else
				echo PUBLIC_FOLDER."/img/Movie/Thumbs/default.png";
		?>
		"/>
			
	<div id="movieInfoContainer">
	<div id="movieInfo">
	<h2 class="headline"><?php echo $movie[0]['Movie']['movieName'];?></h2>
	<?php
	echo '<p>' .$movie[0]['Movie']['movieLength'] . '</p>';
	echo '<p>' .$movie[0]['Movie']['movieGenre'] . '</p>';
	echo '<p>' .$movie[0]['Movie']['movieIMDB'] . '</p>';?>
	</div>
	</div>
</div>

<div id="agents" class="darkGradient">
<h2 class="headline"> Avalable Agents </h2>
<button class="blackBttn" id="agentPollBttn" onClick="sendAJAXRequest('../../Movies/agentPoll',['<?php echo $movie[0]['Movie']["movieID"] ?>'],'agentsAJAXReply');"> poll Agents </button>
<div id="agentsAJAXReply"></div>
<div id="replyDiv">
</div>

</div>
