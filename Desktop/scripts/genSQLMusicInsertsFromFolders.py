import sys, os

musicDir = sys.argv[1]
sqlInserts = open('MusicInserts.sql', 'w')
dirPostFix = "";
albumCounter = 1
artistCounter = 1

def genInsertsForArtist(albumCounter, artistCounter,rootDir, artistdir, file):
    file.write("INSERT INTO Artist VALUES(NULL,'"+artistdir.replace("'","\\'")+"', 0, 'Unknown');\n")

    for albums in os.listdir(rootDir+"/"+artistdir):
        print albums
        genInsertsForAlbum(artistCounter,albumCounter,rootDir, albums,artistdir, file)
	albumCounter = albumCounter +1
	
    return albumCounter
    
def genInsertsForAlbum(artistCounter,albumCounter,rootDir, albumdir,artist, file):
    file.write("INSERT INTO Album VALUES(NULL,'"+albumdir.replace("'","\\'")+
               "',"+str(artistCounter)+",'0000',0);\n")

    for song in os.listdir(rootDir+"/"+artist+"/"+albumdir):
        file.write("INSERT INTO Song VALUES(NULL,'"+song.replace("'","\\'")+
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
    albumCounter = genInsertsForArtist(albumCounter,artistCounter,musicDir.replace("'","\\'"),file, sqlInserts)
    artistCounter = artistCounter+1

sqlInserts.close()
