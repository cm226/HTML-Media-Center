/*
	Author : Craig Matear
*/
#include<boost/filesystem.hpp>
#include "MusicMissingImageContentFinder.h"
#include "../../../../JARVISCoreModules/CoreModules/config.h"

#include "../../../../JARVISCoreModules/CoreModules/Database/Tables/Artist/Artist.h"

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
	DatabaseTables::Artist::Artist artist;
	DatabaseTables::Query artistQuery;

	artistQuery.addSelectItem(&artist);

	this->databaseHandle->runQuery(&artistQuery);

	while(artistQuery.nextLine())
	{
		if(!this->checkArtistThumbnailImageExists(artist.artistName->getValue()))
		{
			artistName = artist.artistName->getValue();
			artistID = artist.artistID->getValue();
			return true;
		}
	}

	return false;
}
bool MusicMissingImageContentFinder::checkArtistThumbnailImageExists(std::string artistName)
{
	std::string thumbImageName;
	thumbImageName = this->imageContentURL +"\\"+ artistName + ".png"; 
	return boost::filesystem::exists(thumbImageName);
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



