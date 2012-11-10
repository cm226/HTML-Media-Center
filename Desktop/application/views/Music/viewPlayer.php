<html>
<head>

<script>
var myPlaylist = [

<?php foreach ($songs as &$song) { ?>

    {
        mp3:<?php echo "'".str_replace("'","\'",str_replace(" ", "%20", $song["Song"]["songURL"] ))."'";?>,
        title:<?php echo "'".str_replace("'","\'", $song["Song"]["songName"]) ."'";?>,
        artist:<?php echo "'".str_replace("'","\'",$song['Artist']['artistName'])."'" ;?>,
        rating:4,
        duration:<?php echo "'". $song["Song"]["songLength"] ."'";?>,
        cover:'../public/img/Music/Albums/<?php echo str_replace("'","\'",$song["Album"]["albumName"]); ?>.png'
    },
	
<?php } ?>
];

</script>
<script type="text/javascript" src="<?php echo PUBLIC_FOLDER; ?>/js/helperFunctions.js"></script> 

    <link rel="stylesheet" type="text/css" href="<?php echo PUBLIC_FOLDER; ?>/swf/plugin/css/style.css">

	<script type="text/javascript" src="<?php echo PUBLIC_FOLDER; ?>/js/jquery-1.6.1.min.js"></script>
	<script type="text/javascript" src="<?php echo PUBLIC_FOLDER; ?>/swf/plugin/jquery-jplayer/jquery.jplayer.js"></script>
    
    <script type="text/javascript" src="<?php echo PUBLIC_FOLDER; ?>/swf/plugin/ttw-music-player-min.js"></script>
    

    <script type="text/javascript">
        $(document).ready(function(){
            var description = 'This is a description of the music being played here???';

            $('body').ttwMusicPlayer(myPlaylist, {
                autoPlay:true, 
                description:description,
                jPlayer:{
                    swfPath:'../../../public/swf/plugin/jquery-jplayer' //You need to override the default swf path any time the directory structure changes
                }
            });
        });
    </script></head>

<body>

</body>
</html>

