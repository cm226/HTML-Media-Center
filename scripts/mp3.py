import eyeD3, os

dir = r'/Users/dimitrispapangelis/Music/My Music/Info/We_Choose_the_Moon/'


files = []
for file in os.listdir(dir):
	if file[-4:] == ".mp3":
		files.append(file)

os.chdir(dir)
for file in files:
	tag = eyeD3.Tag()
	tag.link(file)

	artist = tag.getArtist()
	album = tag.getAlbum()
	title = tag.getTitle()
	print "Title:",title




# 	audio = MP3(dir, ID3=EasyID3)
# 	title = audio.get("TIT2")
# 	artist = audio.get("TPE1")
# 	album = audio.get("TALB")
# 	year = audio.get("TDRC")
# 	track_no = audio.get("TRCK")
# 	kind = audio.get("TCON")
# 	print "song is:",title,"\nby:",artist,"\nalbum:",album,"\nkind:",kind,"\n"