<div data-role="page" data-theme="a">
<div data-role="header" >
    <h1>Music</h1>
	<a href="<?php echo WEB_ROOT;?>Start/Home" data-role="button" data-icon="home" data-iconpos="notext" data-theme="a" data-inline="true">Home</a>
	    <a href="#popupMenu" data-rel="popup" data-role="button" data-inline="true" data-transition="slideup" data-icon="gear" data-theme="a" data-iconpos="notext"></a>
		<div data-role="popup" id="popupMenu" data-theme="a">
			<ul id="resultPopup" data-role="listview" data-inset="true" style="min-width:210px;" data-theme="d">
			    <li data-theme="c"><a href="<?php echo WEB_ROOT;?>Music/remoteControl">Remote Control</a></li>
			</ul>
		</div>

<div data-role="navbar">
        <ul>
            <li><a rel="external" href="<?php echo WEB_ROOT;?>Music/viewAll" >Artists</a></li>
            <li><a href="<?php echo WEB_ROOT;?>Music/viewAlbums">Albums</a></li>
            <li><a href="#">Playlists</a></li>
            <li><a rel="external" href="<?php echo WEB_ROOT;?>Music/viewShuffle" >Shuffle</a></li>
        </ul>
    </div><!-- /navbar -->

</div>
