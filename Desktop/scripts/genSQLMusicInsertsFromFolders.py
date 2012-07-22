import sys, os

musicDir = sys.argv[1]
sqlInserts = open('MusicInserts.sql', 'w')
dirPostFix = "/mix/Music/";
albumCounter = 1

def genInsertsForArtist(albumCounter, rootDir, artistdir, file):
    file.write("INSERT INTO Artist VALUES('"+artistdir.replace("'","\\'")+"', 0, 'Unknown');\n")

    for albums in os.listdir(rootDir+"/"+artistdir):
        genInsertsForAlbum(albumCounter,rootDir, albums,artistdir, file)
	albumCounter = albumCounter +1
	
    return albumCounter
    
def genInsertsForAlbum(albumCounter,rootDir, albumdir,artist, file):
    file.write("INSERT INTO Album VALUES(NULL,'"+albumdir.replace("'","\\'")+
               "','"+artist.replace("'","\\'")+"','0000',0);\n")

    for song in os.listdir(rootDir+"/"+artist+"/"+albumdir):
        file.write("INSERT INTO Song VALUES('"+song.replace("'","\\'")+
                   "', "+str(albumCounter)+
                   ", '00:00:00', 0, 0, '"+
                   dirPostFix.replace("'","\\'")+
                   artist.replace("'","\\'")+"/"+
                   albumdir.replace("'","\\'")+"/"+
                   song.replace("'","\\'")+"'); \n")

if not os.path.exists(musicDir):
    print "Error music directory not found"
    exit

for file in os.listdir(musicDir):
    albumCounter = genInsertsForArtist(albumCounter,musicDir.replace("'","\\'"),file, sqlInserts)

sqlInserts.close()
