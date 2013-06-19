
<!--
<video width="640" height="480" controls> 
<source src="<?php echo $movieURL; ?>" type='video/mp4; codecs="avc1.42E01E, mp4a.40.2"'> 
</video>
-->

<embed type="application/x-vlc-plugin"
         name="video1"
         autoplay="no" loop="yes" width="400" height="300"
		 target="http://localhost/HTML-Media-Center/Desktop/public<?php echo $movieURL; ?>"
         />
		 <!--target="http://localhost/HTML-Media-Center/Desktop/public/mix/Movies/28.Weeks.Later.avi"-->
		 
		 