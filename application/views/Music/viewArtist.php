
<h3>Showing songs for : <?php echo $artistsName; ?> </h3>

<script>
var myPlaylist = [

<?php foreach ($songs as &$song) { ?>

    {
        mp3:<?php echo "'". $song["Url"] ."'";?>,
        title:<?php echo "'". $song["Name"] ."'";?>,
        artist:<?php echo "'".$artistsName."'" ;?>,
        rating:4,
        buy:'#',
        price:'0.99',
        duration:<?php echo "'". $song["Length"] ."'";?>,
        cover:'../public/mix/1.png'
    },
	
<?php } ?>
];

</script>



