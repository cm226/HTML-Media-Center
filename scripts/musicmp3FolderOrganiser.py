import eyeD3, os, sys
from shutil import copyfile

type = sys.argv[1];
song = sys.argv[2];
print type
print song

def moveFile(oldName, artist, album, song):
		try:
			if not os.path.exists(artist):
					os.makedirs(artist)
					
			if not os.path.exists(artist+"/"+album):
					os.makedirs(artist+"/"+album)
			copyfile(oldName, artist+"/"+album+"/"+song+".mp3")
		except:
			print "COPY ERROR: something went wrong copying "+ oldName+ "continueing..";

if type == "-f":
	print "Treating the argument as a file"
	tag = eyeD3.Tag()
	tag.link(song)

	artist = tag.getArtist()
	album = tag.getAlbum()
	title = tag.getTitle()
	print "Title:",title
	print "Artist:",artist
	print "album:",album


elif type == "-d":
	print "Treating the argument as a directory"
	files = []
	for file in os.listdir(song):
		if file[-4:] == ".mp3":
			files.append(file)
		else:
                        print "Error "+file+" is not .mp3 file"

	os.chdir(song)
	for file in files:
		tag = eyeD3.Tag()
		tag.link(file)

		artist = tag.getArtist()
		album = tag.getAlbum()
		title = tag.getTitle()
		moveFile(file,artist,album,title)







# 	audio = MP3(dir, ID3=EasyID3)
# 	title = audio.get("TIT2")
# 	artist = audio.get("TPE1")
# 	album = audio.get("TALB")
# 	year = audio.get("TDRC")
# 	track_no = audio.get("TRCK")
# 	kind = audio.get("TCON")
# 	print "song is:",title,"\nby:",artist,"\nalbum:",album,"\nkind:",kind,"\n"
