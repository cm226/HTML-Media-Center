
    <link rel="stylesheet" type="text/css" href="../public/swf/plugin/css/style.css">
	

	<script type="text/javascript" src="../public/js/jquery-1.6.1.min.js"></script>
	<script type="text/javascript" src="../public/swf/plugin/jquery-jplayer/jquery.jplayer.js"></script>
    
    <script type="text/javascript" src="../public/swf/plugin/ttw-music-player-min.js"></script>
    

    <script type="text/javascript">
        $(document).ready(function(){
            var description = 'This is a description of the music being played here???';

            $('body').ttwMusicPlayer(myPlaylist, {
                autoPlay:false, 
                description:description,
                jPlayer:{
                    swfPath:'../../../public/swf/plugin/jquery-jplayer' //You need to override the default swf path any time the directory structure changes
                }
            });
        });
    </script>