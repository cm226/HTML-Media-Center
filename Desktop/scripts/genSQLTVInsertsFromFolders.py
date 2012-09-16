import sys, os

TVDir = sys.argv[1]
sqlInserts = open('TVInserts.sql', 'w')
dirPostFix = "/mix/TV/";

seasonID = 0

def genSeriesInserts(folderName, SeriesDir):
        query = "INSERT INTO Series VALUES ('"+folderName+"',0,'2012','');"
        sqlInserts.write(query + "\n")
        
        for Season in os.listdir(SeriesDir+"/"+folderName):
                genInsertsForSeason(Season, SeriesDir+"/"+folderName, folderName)
                

def genInsertsForSeason(Season, seriesDir, seriesName):
	query = "INSERT INTO Season VALUES ( NULL,'"+seriesName.replace("'","\\'")+"',"+Season.replace("'","\\'")+");"
	global seasonID
	seasonID = seasonID+1
	sqlInserts.write(query + "\n")
	
        for Episode in os.listdir(seriesDir+"/"+Season):
                epQueery = "INSERT INTO Episode VALUES(NULL, 0,'"+Episode.replace("'","\\'")+"', '00:00:00', 0,"+str(seasonID)+",'"+dirPostFix+seriesName.replace("'","\\'")+"/"+Season.replace("'","\\'")+"/"+Episode.replace("'","\\'")+"');"
               	sqlInserts.write(epQueery + "\n")

for season in os.listdir(TVDir):
        if not season == "TVInserts.sql":
        	genSeriesInserts(season, TVDir)
	
sqlInserts.close()
