<html>
<head>

<script type="text/javascript" src="../public/js/helperFunctions.js"></script> 

<script>


var myPlaylist = [

<?php foreach ($songs as &$song) { ?>

    {
        mp3:<?php echo "'".str_replace(" ","%20",str_replace("'","\'",$song["Song"]["songURL"])) ."'";?>,
        title:<?php echo "'". str_replace("'","\'",$song["Song"]["songName"]) ."'";?>,
        artist:<?php echo "'".str_replace("'","\'",$song['Artist']['artistName'])."'" ;?>,
        rating:4,
        duration:<?php echo "'". $song["Song"]["songLength"] ."'";?>,
        cover:'../public/img/Music/Albums/<?php echo str_replace("'","\'",$song["Album"]["albumName"]); ?>.png',
		id: <?php echo $song['Song']['songID']; ?>
    },
	
<?php } ?>
];

var shuffleOn = false;
var currentSong = -1;
var prevSong = -1;
var numSongs = <?php echo count($songs)."; \n"; ?>
var allSongsPlayedEvnt = new Event();



function songsFinished()
{
	allSongsPlayedEvnt.execute();
}



// player functions


function fillAudio(src)
{
	var audioStr = "<audio controls=\"controls\" id=\"audioPlayer\" onended=\"playNext();\">";
	audioStr += "<source src=\""+ src+"\" type=\"audio/mp3\"/> </audio>";
	
	var audioDiv = document.getElementById('audioControls');
	audioDiv.innerHTML = audioStr;
}

function fillAudioInfo(Name, Artist)
{
	var AudioInfoStr = "<div id=\"songHeader\"><div id=\"SongName\">"+Name+" - </div>";
	AudioInfoStr+= "<div id=\"ArtistName\"> "+Artist+"</div></div>";

	var songInfo = document.getElementById('currentSongInfo');
	songInfo.innerHTML = AudioInfoStr;
}

function fillAlbumImage(url)
{
	var albumImgStr = "<img src=\""+url+"\" id=\"Albumimgtag\" height=\"50%\" width=\"auto\"/>";

	var albumImg = document.getElementById('albumImage');
	albumImg.innerHTML = albumImgStr;
	
}
function shuffle()
{
	if(shuffleOn)
		shuffleOn = false;
	else
		shuffleOn = true;
}

function playNext()
{
	prevSong = currentSong;
	currentSong++;
	if(currentSong >= numSongs)
		songsFinished();
	else
		play();
}

function playPrev()
{
	songsFinished();
	prevSong = currentSong 
	currentSong--;
	play();
}

function playSong(number)
{
	prevSong = currentSong 
	currentSong = number;
	play();
}

function play()
{
	if(shuffleOn)
	{
		var randomnumber=Math.floor(Math.random()*numSongs)+1;

		while(randomnumber == currentSong)
			randomnumber = Math.floor(Math.random()*numSongs)+1;
	
		currentSong = randomnumber;
	}

	
	fillAudio(myPlaylist[currentSong].mp3);
	fillAudioInfo(myPlaylist[currentSong].title, myPlaylist[currentSong].artist);
	fillAlbumImage(myPlaylist[currentSong].cover);
	updatePlayingList(prevSong,currentSong);
	
	document.getElementById('audioPlayer').play();
}

function downloadSong(songNumber)
{
	var id = myPlaylist[songNumber].id;
	window.location = "../Music/downloadSong/"+String(id);
}

function updatePlayingList(from, to)
{
	var nowPlaying = document.getElementById("playlist"+to);
	nowPlaying.style.color = "Black";
	nowPlaying.style.fontSize = "large";

	if(from != -1)
	{
		var wasPlaying = document.getElementById("playlist"+from);
		wasPlaying.style.color = "Black";
		wasPlaying.style.fontSize = "small";
	}
}


</script>

<link rel="stylesheet" type="text/css" href="../public/css/musicViewPlayer.css">
</head>

<body>

	<div id="player" >
		<div id="currentSongInfo" style="background-image:url(<?php echo "'".PUBLIC_FOLDER. "/img/Music/icons/HeaderGradient.png"."'";?>);">
		<div id= "playlistsIcng"><img src="<?php echo PUBLIC_FOLDER. "/img/Music/icons/playlistsIcon.png";?>" height="30px" width="30px"></div>
		</div>
		<div id="albumImage"></div>
		<div id="currentlyPlaying"></div>
		<div id="audioControls"></div>
		
		<div id="playerControls" style="background-image:url(<?php echo "'".PUBLIC_FOLDER. "/img/Music/icons/PlayerGradient.png"."'";?>);">
		<div id="center">
			<div id="prevBttn" onClick="playPrev();" >
				<img src="<?php echo PUBLIC_FOLDER. "/img/Music/icons/prev.png"; ?>" height="50px" width="50px"></img>			
			</div>
			<div id="playBttn" onClick="playNext();">
				<img src="<?php echo PUBLIC_FOLDER. "/img/Music/icons/play.png"; ?>" height="100px" width="100px"></img>			
			</div>
			<div id="nextBttn" onClick="playNext();">
				<img src="<?php echo PUBLIC_FOLDER. "/img/Music/icons/next.png"; ?>" height="50px" width="50px"></img>			
			</div>
			
		</div>
		<div id="shuffleButton" onclick="shuffle(); play();">
				<img src="<?php echo PUBLIC_FOLDER. "/img/Music/icons/shuffle.png"; ?>" height="50px" width="50px"></img>
			</div>
			

		</div>
	</div>

<script>
	var playingList = document.getElementById('currentlyPlaying');
	
	for(var i = 0; i < numSongs; i++)
	{
		var songItem = "<div class=\"songItem\" id=\"playlist"+i+"\" onClick=\"playSong("+i+");\">";
		songItem += myPlaylist[i].title;
		songItem += "<div id=\"downloadButton\" onClick=\"downloadSong("+i+")\"> <img src=";
		songItem += <?php echo '"'.PUBLIC_FOLDER. '/img/Music/icons/downloadBttn.png'.'"';?>;
		songItem += " height=\"30px\" width=\"30px\"> </div>";
		songItem += "<div/>";
		
		playingList.innerHTML += songItem;
	}
</script>
</body>
</html>

