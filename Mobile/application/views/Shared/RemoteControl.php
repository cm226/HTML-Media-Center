<?php ?>

<link rel="stylesheet" type="text/css" href="<?php echo PUBLIC_FOLDER .DS . 'css' .DS. 'RemoteControl.css' ?>">

<div id="remote">
	<div id="playbackControl">
			<div id="Stop" class="threePartElement"><img src="<?php echo PUBLIC_FOLDER . DS . "img" . DS . "Shared" .DS. "stop.png"?>"/></div>
			<div id="play" class="threePartElement"><img src="<?php echo PUBLIC_FOLDER . DS . "img" . DS . "Shared" .DS. "play.png"?>"/></div>
			<div id="pause" class="threePartElement"><img src="<?php echo PUBLIC_FOLDER . DS . "img" . DS . "Shared" .DS. "pause.png"?>"/></div>
	</div>
	<div id="seek">
		<div id="seekLeft" class="twoPartElement"><img src="<?php echo PUBLIC_FOLDER . DS . "img" . DS . "Shared" .DS. "seekLeft.png"?>"/></div>
		<div id="seekRight" class="twoPartElement"><img src="<?php echo PUBLIC_FOLDER . DS . "img" . DS . "Shared" .DS. "seekRight.png"?>"/></div>
	</div>
	<div id="Volume">
		<div id="volumeUp" class="twoPartElement"><img src="<?php echo PUBLIC_FOLDER . DS . "img" . DS . "Shared" .DS. "volumeUp.png"?>"/></div>
		<div id="volumeDown" class="twoPartElement"><img src="<?php echo PUBLIC_FOLDER . DS . "img" . DS . "Shared" .DS. "volumeDown.png"?>"/></div>
	</div>
</div>