/*
	Author : Craig Matear
*/
#include<boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include "MusicMissingImageContentFinder.h"
#include "../../../../JARVISCoreModules/CoreModules/config.h"
#include "../../../../JARVISCoreModules/CoreModules/Errors/ErrorLogger.h"

#include "../../../../JARVISCoreModules/CoreModules/Database/Tables/Artist/Artist.h"
#include "../../../../JARVISCoreModules/CoreModules/Database/Tables/Album/Album.h"

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
	std::string thumbImageName = this->imageContentURL +"\\"+ artistName;
	return checkPNGorJPGImageExsists(thumbImageName);
}

bool MusicMissingImageContentFinder::searchDBforMissingArtistImage(std::string& artistName, int& artistID)
{
	DatabaseTables::Artist::Artist artist;
	DatabaseTables::Query artistQuery;

	artistQuery.addSelectItem(&artist);

	this->databaseHandle->runQuery(&artistQuery);

	while(artistQuery.nextLine())
	{
		if(!this->checkArtistImageExists(artist.artistName->getValue()))
		{
			artistName = artist.artistName->getValue();
			artistID = artist.artistID->getValue();
			return true;
		}
	}

	return false;
}

bool MusicMissingImageContentFinder::checkArtistImageExists(std::string artistName)
{
	std::string artistImageURL = this->imageContentURL +"\\Artists"+ artistName;
	return checkPNGorJPGImageExsists(artistImageURL);
}


bool MusicMissingImageContentFinder::searchDBforMissingAlbumImage(std::string& albumName,std::string& artistName, int& albumID)
{
	DatabaseTables::Album::Album album;
	DatabaseTables::Query albumQuery;

	albumQuery.addSelectItem(&album);

	this->databaseHandle->runQuery(&albumQuery);

	while(albumQuery.nextLine())
	{
		if(!this->checkAlbumImageExists(album.albumName->getValue()))
		{
			albumName = album.albumName->getValue();
			albumID = album.albumID->getValue();

			DatabaseTables::Query artistQuery;
			DatabaseTables::Artist::Artist albumArtist;
			DatabaseTables::Equals eqConstraint(albumArtist.artistID,album.artistID);

			artistQuery.addConstraint(&eqConstraint);
			artistQuery.addSelectItem(&albumArtist);
			this->databaseHandle->runQuery(&artistQuery);

			if(artistQuery.nextLine())
				artistName = albumArtist.artistName->getValue();
			else
				ErrorLogger::logError("No results found when looking for Artist of album, Database corruption?");

			return true;
		}
	}
	return false;
}

bool MusicMissingImageContentFinder::checkAlbumImageExists(std::string albumName)
{
	std::string albumImageFilename =  this->imageContentURL +"\\Album"+ albumName;
	return checkPNGorJPGImageExsists(albumImageFilename);
}

#ifdef WIN32
#include <Windows.h>


BOOL FileExists(std::string path)
{

	//std::wstring szPath(path.begin(), path.end());
	DWORD dwAttrib = GetFileAttributes(path.c_str());

  return (dwAttrib != INVALID_FILE_ATTRIBUTES && 
         !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}


#endif

bool MusicMissingImageContentFinder::checkPNGorJPGImageExsists(std::string fileName)
{
	// boost filesystem seems to crash when we use large file dirs, so we wil just do it nativly

	std::string pngFileName = fileName+".png";
	std::string jpegFileName = fileName+".jpg";

	if(FileExists(pngFileName) || FileExists(jpegFileName))
		return true;

	return false;
}


}
}



