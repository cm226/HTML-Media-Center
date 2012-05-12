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
var currentSong = 0;
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
	var audioStr = "<audio controls=\"controls\" id=\"audioPlayer\">";
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

	document.getElementById('audioPlayer').play();
}

</script>

<link rel="stylesheet" type="text/css" href="../public/css/musicViewPlayer.css">
</head>

<body>

	<div id="player" >
		<div id="playerControls">
			<div id="shuffleButton" onclick="shuffle(); playNext();">
				shuffle
			</div>
			<div id="nextBttn" onClick="currentSong++; playNext();">next</div>
		</div>
		<div id="currentSongInfo"></div>
		<div id="albumImage"></div>
		<div id="audioControls"></div>
	</div>

	
</body>
</html>

