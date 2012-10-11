import sys, os

movieDir = sys.argv[1]
sqlInserts = open('MovieInserts.sql', 'w')
dirPostFix = "/mix/Movie/";

def genInsertsForMovie(fileName):
        movieName = fileName.replace("'","\\'");
        movieName = movieName[:-4]
        
	query = "INSERT INTO Movie VALUES ( NULL, '"+movieName+"','"+dirPostFix+"/"+fileName+"',"+"0,"+"'00:00:00',"+"'',"+"'')"
										
	sqlInserts.write(query+"; \n")
										

for movie in os.listdir(movieDir):
	genInsertsForMovie(movie)
	
sqlInserts.close()
