#!/usr/bin/env python

import os
from xml.dom.minidom import parseString

linksFile = open("symbolicLinks.xml")
symLinks = linksFile.read()
dom = parseString(symLinks)
linksFile.close()

def getLinks(linkTo):
	symlinks = [];
	for musicTag in dom.getElementsByTagName(linkTo):
		for link in musicTag.getElementsByTagName("link"):
			symlinks.append(link.firstChild.data)

	return symlinks

# this is how to get the link list change later to accualy crate the linke
print getLinks("Music");
print getLinks("Tv");
print getLinks("Pictures");
print getLinks("Movies");

Desktop = "../"

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


configFile = ["<?php\n",
			"/** Configuration Variables **/\n",
			"define ('DEVELOPMENT_ENVIRONMENT',true);\n",
			"define('DB_NAME', 'dbName');\n",
			"define('DB_USER', 'user');\n",
			"define('DB_PASSWORD', 'pw');\n",
			"define('DB_HOST', 'localhost');\n",
			"$GLOBALS['ignoreHeader'] = array('viewPlayer'););\n"
			];

config = open(Desktop + "config/config.php","w")
config.writelines(configFile);



