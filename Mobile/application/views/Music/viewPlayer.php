<html>
<head>

<script>

var myPlaylist = [

<?php foreach ($songs as &$song) { ?>

    {
        mp3:<?php echo "'".PUBLIC_FOLDER. str_replace(" ","%20",$song["Song"]["songURL"]) ."'";?>,
        title:<?php echo "'". $song["Song"]["songName"] ."'";?>,
        artist:<?php echo "'".$song['Album']['artistName']."'" ;?>,
        rating:4,
        duration:<?php echo "'". $song["Song"]["songLength"] ."'";?>,
        cover:'../public/img/Music/Albums/<?php echo $song["Album"]["albumName"]; ?>.png'
    },
	
<?php } ?>
];

var shuffleOn = false;
var currentSong = -1;
var prevSong = -1;
var numSongs = <?php echo count($songs); ?>

function shuffle()
{
	if(shuffleOn)
		shuffleOn = false;
	else
		shuffleOn = true;
}

function fillAudio(src)
{
	var audioStr = "<audio controls=\"controls\" id=\"audioPlayer\" onended=\"playNext();\">";
	audioStr += "<source src=\""+ src+"\" type=\"audio/mp3\"/> </audio>";
	
	var audioDiv = document.getElementById('audioControls');
	audioDiv.innerHTML = audioStr;
}

function fillAudioInfo(Name, Artist)
{
	var AudioInfoStr = "<h4 id=\"SongName\">"+Name+"</h4>";
	AudioInfoStr+= "<h4 id=\"ArtistName\">"+Artist+"</h4>";

	var songInfo = document.getElementById('currentSongInfo');
	songInfo.innerHTML = AudioInfoStr;
}

function fillAlbumImage(url)
{
	var albumImgStr = "<img src=\""+url+"\" id=\"Albumimgtag\" height=\"50%\" width=\"auto\"/>";

	var albumImg = document.getElementById('albumImage');
	albumImg.innerHTML = albumImgStr;
	
}

function playNext()
{
	prevSong = currentSong;
	currentSong++;
	play();
}

function playPrev()
{
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
		<div id="currentSongInfo"></div>
		<div id="albumImage"></div>
		<div id="currentlyPlaying"></div>
		<div id="audioControls"></div>
		<div id="playerControls">
			<div id="prevBttn" onClick="playPrev();">
				<img src="<?php echo PUBLIC_FOLDER. "/img/Music/icons/prev.png"; ?>" height="50px" width="50px"></img>			
			</div>
			<div id="shuffleButton" onclick="shuffle(); play();">
				<img src="<?php echo PUBLIC_FOLDER. "/img/Music/icons/shuffle.png"; ?>" height="50px" width="50px"></img>
			</div>
			<div id="nextBttn" onClick="playNext();">
				<img src="<?php echo PUBLIC_FOLDER. "/img/Music/icons/next.png"; ?>" height="50px" width="50px"></img>			
			</div>
			

		</div>
	</div>

<script>
	var playingList = document.getElementById('currentlyPlaying');
	
	for(var i = 0; i < numSongs; i++)
	{
		playingList.innerHTML += "<div class=\"songItem\" id=\"playlist"+i+"\" onClick=\"playSong("+i+");\">"+myPlaylist[i].title+"<div/>";
	}
</script>
</body>
</html>

