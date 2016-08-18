
<ul data-role="listview" data-autodividers="true" data-filter="true" data-inset="true">
    <?php

	foreach($albums as $album)
	{
		?> <li><a href="../../Mobile/Music/viewAlbum/<?php echo $album['Album']['albumID'];?>"><?php echo $album['Album']['albumName'];?></a></li> <?php
	}

 ?>
</ul>



