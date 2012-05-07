<html>
<head>

<script>
var myPlaylist = [

<?php foreach ($songs as &$song) { ?>

    {
        mp3:<?php echo "'". $song["Song"]["songURL"] ."'";?>,
        title:<?php echo "'". $song["Song"]["songName"] ."'";?>,
        artist:<?php echo "'".$song['Album']['artistName']."'" ;?>,
        rating:4,
        duration:<?php echo "'". $song["Song"]["songLength"] ."'";?>,
        cover:'../public/img/Music/Albums/<?php echo $song["Album"]["albumName"]; ?>.png'
    },
	
<?php } ?>
];

var shuffleOn = false;
var numSongs = <?php echo count($songs); ?>

function shuffle()
{
	if(shuffleOn)
		shuffleOn = false;
	else
		shuffleOn = true;
}

function playNext(not)
{
	var randomnumber=Math.floor(Math.random()*numSongs)+1;

	while(randomnumber == not)
		randomnumber = Math.floor(Math.random()*numSongs)+1;

	document.getElementById('song'+randomnumber).play();
}

</script>

<link rel="stylesheet" type="text/css" href="../public/css/musicViewPlayer.css">
</head>

<body>

	<div id="player" >
		<div id="shuffleButton" onclick="shuffle(); playNext(-1);">
			shuffle
		</div>
		<?php $soungCount = 0; ?>
		<?php foreach ($songs as &$song) { $songCount++; ?>
		<div class = "song">
			<div class ="title">
				<?php echo $song["Song"]["songName"];?>
			</div>
			<div class="player">
			<audio controls="controls" id="song<?php echo $songCount; ?>" preload="none" OnEnded="playNext('<?php echo $songCount; ?>')">
				<source src="<?php echo PUBLIC_FOLDER; echo str_replace(" ", "%20", $song["Song"]["songURL"]) ;?>" type="audio/mp3" />
			</audio>
			</div>
		</div>
		<?php } ?>
	</div>
</body>
</html>

