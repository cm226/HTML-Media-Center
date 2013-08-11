<div id="episode">
<div id="episodename"> <?php echo $URL[0]['Episode']['episodeName']?></div>
<div id="episodeplayCount"> <?php echo $URL[0]['Episode']['episodePlayCount']?></div>
<div id="episodeLength"> <?php echo $URL[0]['Episode']['episodeLength']?></div>
</div>

<div id="avalableAgents">
	<div id="agentsHeader">
		Avalable Agents
	</div>
	<?php 
		foreach ($Agents as $agent)
		{
			?>
			
			<div id="agent" onclick="playMovie(<?php echo "'".$agent["IP"]."', '".$URL[0]['Episode']['episodeID']."'"?>);">
				<?php echo $agent['Name'];?>
				<?php echo $agent['Location'];?>
			</div>
			
			<?php
		}
	?>
</div>

<div id="replyDiv">
</div>

<div id="EpisodeDetails" >
<h3>Update Episode Details</h3>
<form>
Episode Name: <input type="text"/> <br/>
Episode Number: <select>
	<option value="1">1</option>
	<option value="2">2</option>
	<option value="3">3</option>
	<option value="4">4</option>
</select><br/>
<input type="submit" value="Update"/> 
</form>



</form>


</div>