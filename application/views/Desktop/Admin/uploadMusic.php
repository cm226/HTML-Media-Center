<?php 

	if(isset($ReturnCode) || isset($exsists) || isset($InvalidFileType))
	{
		?>
		<div id="errorDiv">
		
		<?php
			if(isset($ReturnCode))
			{
				echo 'seems there was a problem uploading : '. $ReturnCode;
			}

			if(isset($exsists))
			{
				echo 'That file already exsists... y u be trollin? ';
			}

			if(isset($InvalidFileType))
			{
				echo 'lol... invalid file type noob... ';
			}
			
		?>
		</div>
		<?php
	}
	else
	{
		?>
		<div id="allIsGd">
			Music File sucssefully uploaded
		</div>
		<?php
	}
?>
