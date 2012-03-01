from mutagen.mp3 import MP3
from mutagen.easyid3 import EasyID3

import os
dir = os.listdir("/Users/dimitrispapangelis/Music/My Music/Info/We_Choose_the_Moon/")

for filename in dir:
	print filename
    audio = MP3(filename, ID3=EasyID3)
# 	title = audio.get("TIT2")
# 	artist = audio.get("TPE1")
# 	album = audio.get("TALB")
# 	year = audio.get("TDRC")
# 	track_no = audio.get("TRCK")
# 	kind = audio.get("TCON")
# 	print "song is:",title,"\nby:",artist,"\nalbum:",album,"\nkind:",kind,"\n"