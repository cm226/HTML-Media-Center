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

</script>

<link rel="stylesheet" type="text/css" href="../public/css/musicViewPlayer.css">
</head>

<body>

	<div id="player" >
	
		<?php foreach ($songs as &$song) { ?>
		<div class = "song">
			<div class ="title">
				<?php echo $song["Song"]["songName"];?>
			</div>
			<div class="player">
			<audio controls="controls">
				<source src="<?php echo str_replace(" ", "%20", $song["Song"]["songURL"]) ;?>" type="audio/mp3" />
			</audio>
			</div>
		</div>
		<?php } ?>
	</div>
</body>
</html>

