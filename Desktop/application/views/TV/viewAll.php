
<div id="pagecontent">

	<div id="seriesSelection">
	<form>
	Name: <input type="text" />
	</form>
	<div id="seriesContainer">
		<?php
			foreach ($seriesNames as $name)
			{
				echo '<div class="series" ><a href="'. PUBLIC_FOLDER .'/../TV/viewAll/'. $name['Series']['seriesName'] .'">
						' . $name['Series']['seriesName'] . ' </a>
				
				</div>';
			}
		?>
	</div>
	</div>
	<div id="seasonSelection">
		<div id="headerDiv" >
			<?php if(isset($seriesName)) { ?>
			<img id="seriesImage" src="<?php echo PUBLIC_FOLDER;?>/img/TV/seriesThumbs/<?php echo $seriesName;?>.png" height="150" width="100"/>
			<h3 id="seriesTitle" > <?php echo $seriesName;?> </h3>
			<?php }?>
		</div>
		
		<?php
			if(isset($seasons))
			{
				foreach ( $seasons as $season)
				{
					echo '<div id="seasonsDiv">
						<div class="season">
							<h4> season ' . $season['Season']['seriesNumber'] . ' </h4>';
							
							foreach ($episodes[$season['Season']['seriesNumber']] as $episode)
							{
								echo '<div class="episode" onclick="location.href=\'../../TV/viewEpisode/'. str_replace(' ','%20',$episode['Episode']['episodeName']) . '\';"> 
										<div class="number"> 1 </div>
										<div class="name">'. $episode['Episode']['episodeName'] . '</div>
										<div class="length">00:45:00</div>
									  </div>';
							}
							
					echo '</div>';
					
				}
			}
		?>
		
		</div>
	</div>

</div>
