
<div id="pagecontent">

	<div id="seriesSelection">
	<h4> filter series </h4>
	<form>
	Name: <input type="text" />
	</form>
	<div id="seriesContainer">
		<?php
			foreach ($seriesNames as $name)
			{
				echo '<div class="series" ><a href="'. $publicFolder .'TV/viewAll/'. $name['Series']['seriesName'] .'">
						' . $name['Series']['seriesName'] . ' </a>
				
				</div>';
			}
		?>
	</div>
	</div>
	<div id="seasonSelection">
		<div id="headerDiv" >
			<?php if(isset($seriesName)) { ?>
			<img id="seriesImage" src="<?php echo $publicFolder;?>/public/img/TV/seriesThumbs/<?php echo $seriesName;?>.png" height="150" width="100"/>
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
								echo '<a href="../../TV/viewEpisode/'.$episode['Episode']['episodeName'].'"> 
										<div class="episode">'. $episode['Episode']['episodeName'] . '</div>
									  </a>';
							}
							
					echo '</div>';
					
				}
			}
		?>
		
		</div>
	</div>

</div>