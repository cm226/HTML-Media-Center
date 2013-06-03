#!/usr/bin/env python

import os
import sys
from xml.dom.minidom import parseString


linksFile = open("symbolicLinks.xml")
symLinks = linksFile.read()
dom = parseString(symLinks)
linksFile.close()

def getLinks(linkTo):
	symlink = None;
	link = dom.getElementsByTagName(linkTo)
	symlinks = link[0].firstChild.data

	return symlinks.encode('ascii', 'ignore')


Desktop = "../"
Public = Desktop+"public/"
if not os.path.exists(Public+"mix"):
	os.makedirs(Public+"mix")

if sys.platform.startswith('win'):
	import ctypes
	kdll = ctypes.windll.LoadLibrary("kernel32.dll")
	
	print getLinks("Music")
	
	if not os.path.exists(Public+"mix/Music"):
		kdll.CreateSymbolicLinkA(Public+"mix/Music",getLinks("Music"),1)
	if not os.path.exists(Public+"mix/Tv"):
		kdll.CreateSymbolicLinkA(Public+"mix/Tv",getLinks("Tv"),1)
	if not os.path.exists(Public+"mix/Pictures"):
		kdll.CreateSymbolicLinkA(Public+"mix/Pictures",getLinks("Pictures"),1)
	if not os.path.exists(Public+"mix/Movies"):
		kdll.CreateSymbolicLinkA(Public+"mix/Movies",getLinks("Movies"),1)


else:
	if not os.path.exists(Public+"mix/Music"):
		os.symlink(getLinks("Music"),Public+"mix/Music")
	if not os.path.exists(Public+"mix/Tv"):
		os.symlink(getLinks("Tv"),Public+"mix/Tv")
	if not os.path.exists(Public+"mix/Pictures"):
		os.symlink(getLinks("Pictures"),Public+"mix/Pictures")
	if not os.path.exists(Public+"mix/Movies"):
		os.symlink(getLinks("Movies"),Public+"mix/Movies")
	



# create temp upload folders
if not os.path.exists(Desktop + "tempUploads/"):
    os.makedirs(Desktop + "tempUploads/")

if not os.path.exists(Desktop + "tempUploads/Music"):
    os.makedirs(Desktop + "tempUploads/Music")

if not os.path.exists(Desktop + "tempUploads/TV"):
    os.makedirs(Desktop + "tempUploads/TV")

if not os.path.exists(Desktop + "tempUploads/Pictures"):
    os.makedirs(Desktop + "tempUploads/Pictures")

if not os.path.exists(Desktop + "tempUploads/Movies"):
    os.makedirs(Desktop + "tempUploads/Movies")

if not os.path.exists(Desktop + "tempUploads/Plugin"):
    os.makedirs(Desktop + "tempUploads/Plugin")

if not os.path.exists(Desktop + "config/config.php","w"):
	configFile = ["<?php\n",
				"/** Configuration Variables **/\n",
				"define ('DEVELOPMENT_ENVIRONMENT',true);\n",
				"define('DB_NAME', 'dbName');\n",
				"define('DB_USER', 'user');\n",
				"define('DB_PASSWORD', 'pw');\n",
				"define('DB_HOST', 'localhost');\n",
				"$GLOBALS['ignoreHeader'] = array('viewPlayer');\n"
				];

	config = open(Desktop + "config/config.php","w")
	config.writelines(configFile);



