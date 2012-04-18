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

function setPlayer()
{
	var player = document.getElementById('player');
	var playerHTML = "<div id=\"playList\">";
	for(var songi in myPlaylist)
	{
		playerHTML+"<div class='song'>"+myPlaylist[songi].title+"</div>";
	}
	playerHTML + "</div>";
	player.innerHTML = ;
}

setPlayer();
</script>
</head>

<body>

	<div id="player" >
	</div>
	<audio controls="controls">
		<source src="../public/mix/Music/Nickelback/animals.mp3" type="audio/mp3" />
	</audio>
</body>
</html>

