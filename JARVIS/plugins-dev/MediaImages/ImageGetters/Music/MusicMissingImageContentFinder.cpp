/*
	Author : Craig Matear
*/
#include "MusicMissingImageContentFinder.h"
#include "../../../../JARVISCoreModules/CoreModules/config.h"

#include "../../../../JARVISCoreModules/CoreModules/Database/Tables/Music/Artist/Artist.h"

namespace imagegetters {
namespace music {



MusicMissingImageContentFinder::MusicMissingImageContentFinder(DatabaseTables::Database* databaseHandle) : databaseHandle(databaseHandle)
{
	this->imageContentURL = std::string(HTMLMEDIAPUBLIC).append("\\img\\Music") ;
}



MusicMissingImageContentFinder::~MusicMissingImageContentFinder()
{
}


bool MusicMissingImageContentFinder::searchDBforMissingArtistThumbImage(std::string& artistName, int& artistID)
{
	//DatabaseTables::Artist artist;


	return false;
}
bool MusicMissingImageContentFinder::searchDBforMissingArtistImage(std::string& artistName, int& artistID)
{
	return false;
}
bool MusicMissingImageContentFinder::searchDBforMissingAlbumImage(std::string& albumName,std::string& artistName, int& albumID)
{
	return false;
}





}
}



