
<h3><?php echo $artistsName; ?> </h3>

<div name="albumList">
<h4> albums </h4>
<?php 
foreach ($albums as $album)
{
	echo '<div id="album"><a href="#" >' . $album['Album']['albumName'] . '</a></div>';

}

?>


</div>

<script>
var myPlaylist = [

<?php foreach ($songs as &$song) { ?>

    {
        mp3:<?php echo "'". $song["Song"]["songURL"] ."'";?>,
        title:<?php echo "'". $song["Song"]["songName"] ."'";?>,
        artist:<?php echo "'".$artistsName."'" ;?>,
        rating:4,
        duration:<?php echo "'". $song["Song"]["songLength"] ."'";?>,
        cover:'../public/mix/1.png'
    },
	
<?php } ?>
];

</script>



