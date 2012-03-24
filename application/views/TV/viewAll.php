
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
				echo '<div class="series" >
						' . $name . '
				
				</div>';
			}
		?>
	</div>
	</div>
	<div id="seasonSelection">
		<div id="headerDiv" >
			<img id="seriesImage" src="../public/img/TV/seriesThumbs/TrueBlood.png" height="150" width="100"/>
			<h3 id="seriesTitle" > True Blood </h3>
		</div>
		
		<div id="seasonsDiv">
			<div class="season">
				<h4> season 1 </h4>
				<a href="../TV/viewEpisode"> ep1 </a>
			</div>
			<div class="season">
				<h4> season 2 </h4>
			</div>
			<div class="season">
				<h4> season 3 </h4>
			</div>
		</div>
	</div>

</div>