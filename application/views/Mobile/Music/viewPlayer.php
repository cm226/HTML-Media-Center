<!DOCTYPE html>
<html>
<head>


<link rel="stylesheet" href="<?php echo PUBLIC_FOLDER;?>/css/Mobile/jquery.mobile-1.3.1.min.css"/>
<link rel="stylesheet" href="<?php echo PUBLIC_FOLDER;?>/css/Mobile/musicViewPlayer.css"/>

<script type="text/javascript" src="<?php echo PUBLIC_FOLDER;?>/js/Mobile/helperFunctions.js"></script> 

<script src="<?php echo PUBLIC_FOLDER;?>/js/Mobile/jquery-1.10.1.min.js"></script>
<script src="<?php echo PUBLIC_FOLDER;?>/js/Mobile/jquery.mobile-1.3.1.min.js"></script>

<script>

$( document ).on( "pageinit", "#musicPlayer", function() {
    $( document ).on( "swipeleft swiperight", "#musicPlayer", function( e ) {
        // We check if there is no open panel on the page because otherwise
        // a swipe to close the left panel would also open the right panel (and v.v.).
        // We do this by checking the data that the framework stores on the page element (panel: open).
        if ( $.mobile.activePage.jqmData( "panel" ) !== "open" ) {
            if ( e.type === "swipeleft"  ) {
                $( "#songPanel" ).panel( "open" );
            }
        }
    }); 
});



var myPlaylist = [

<?php
 foreach ($songs as &$song) { ?>

    {
        mp3:<?php echo "'".PUBLIC_FOLDER."/mix/Music/".str_replace(" ","%20",str_replace("'","\'",$song["Song"]["songURL"])) ."'";?>,
        title:<?php echo "'". str_replace("'","\'",$song["Song"]["songName"]) ."'";?>,
        artist:<?php echo "'".str_replace("'","\'",$song['Artist']['artistName'])."'" ;?>,
        rating:4,
        duration:<?php echo "'". $song["Song"]["songLength"] ."'";?>,
		id: <?php echo $song["Song"]["songID"] ?>,
	<?php 
		if(file_exists(PUBLIC_FOLDER.'/img/Music/Albums/'.str_replace("'","\'",$song["Album"]["albumName"]).'.png'))
		echo 'cover: \''.PUBLIC_FOLDER.'/img/Music/Albums/'. str_replace("'","\'",$song["Album"]["albumName"]).'.png \'';

		else
			echo 'cover: \''.PUBLIC_FOLDER.'/img/Music/Albums/default.jpg\'';

	?>
    },
	
<?php } ?>
];

var numSongs = <?php echo count($songs)."; \n"; ?>

$( document ).ready(function() {
    		$("#playBttn").click(function(){playOrPause();});
		$("#playPrev").click(function(){playPrev();});
		$("#playNext").click(function(){playNext();});

		$("#songContainer ul li a").click(function(event) {
 			 event.preventDefault();
			 playSong($(this).attr("href"));
			});
		
		$("#volumeSlider").change(function() {
		  changeVolume($("#slider-2").val());
		});

	});

function sendPlaylist(destination)
{
	var songs = [];
	for (var i = 0; i < numSongs; i++)
		  songs.push(myPlaylist[i].id);
	 
	 var songList = songs.toString();
	 console.log(songList);
	 
	 $.ajax({
		  type: "POST",
		   url: <?php echo "\"".WEB_ROOT."/Music/playAudioStream\""; ?>, 
		  data: { songs: songList }
		}).done(function( msg )
		{
		  $("#actionResult").html(msg);
		});
}

function getAgents()
{
	 $.ajax({
		  type: "POST",
		   url: <?php echo "\"".WEB_ROOT."/Music/makeAgentQuery\""; ?>
		}).done(function( msg )
		{
			  $("#resultPopup").append(msg);
		});
}


</script>
<script src="<?php echo PUBLIC_FOLDER;?>/js/Mobile/player.js"></script>

<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
</head>

<body>



<div data-role="page" data-theme="a" id="musicPlayer">

<div data-role="header">
	<div data-display="overlay" data-position="right" data-theme="a" data-role="panel" id="songPanel">
		<div id="songContainer">	
		<ul data-role="listview" data-icon="false" data-inset="true" data-filter="false" data-theme="a">

		<?php
		$counter = 0;		
		 foreach ($songs as &$song) 
		{
			echo '<li><a href="'.$counter.'">'.$song["Song"]["songName"].'</a></li>';
			$counter++;
		}?>
		   
		</ul>
		</div>
	</div><!-- /panel -->
</div> <!-- /header -->


<div data-role="content">

<div id="actionResult"></div>

<div data-role="controlgroup" data-type="horizontal" class="localnav">
            <a href="#" data-role="button" data-transition="fade" id="playPrev">Previus</a>
            <a href="#" data-role="button" data-transition="fade" id="playBttn">Play/Pause</a>
            <a href="#" data-role="button" data-transition="fade" id="playNext">Next</a>
</div>

<div id="actionsPopup">
<a href="#popupMenu" data-rel="popup" data-role="button" data-inline="true" data-transition="slideup" data-icon="gear" data-theme="a" data-iconpos="notext"></a>
<div data-role="popup" id="popupMenu" data-theme="a">
        <ul id="resultPopup" data-role="listview" data-inset="true" style="min-width:210px;" data-theme="d">
            <li data-role="divider" data-theme="b">Actions</li>
            <li><a onClick="getAgents();">Stream Playlist</a></li>
        </ul>
</div>
</div>

<div id="currentSong">
	
	
	<div id="songInfo">
		<div id="albumImage">
		</div>

		<div id="currentSongInfo">
			<h5>Album</h5>
			<h3>Song</h3>
		</div>
	</div>
</div>

<div id="audioControls">
</div> 

<div id="volumeSlider">
  <input type="range" name="slider-2" id="slider-2" data-highlight="true" min="0" max="100" value="50">
</div>

</div>


</div>


</body>
</html>

