<?php

$routing = array(
	'/admin\/(.*?)\/(.*?)\/(.*)/' => 'admin/\1_\2/\3'
);

$default['controller'] = 'start';
$default['action'] = 'home';
$GLOBALS['ignoreHeader'] = array('viewPlayer','getArtistAlbums','getArtistBackgrounds','Play');