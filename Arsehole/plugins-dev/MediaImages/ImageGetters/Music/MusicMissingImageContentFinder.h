/*
	Author : Craig Matear
*/
#pragma once
#ifndef IMAGEGETTERS_MUSIC_MUSICMISSINGIMAGECONTENTFINDER_H
#define IMAGEGETTERS_MUSIC_MUSICMISSINGIMAGECONTENTFINDER_H

#include <string>
#include "../../../../arseholeCoreModules/CoreModules/Database/Database.h"
namespace imagegetters {
namespace music {


/**
	MusicMissingImageContentFinder
*/
class MusicMissingImageContentFinder
{
private:
	std::string imageContentURL;
	DatabaseTables::Database* databaseHandle;

	bool checkArtistThumbnailImageExists(std::string artistName);
	bool checkArtistImageExists(std::string artistName);
	bool checkAlbumImageExists(int albumID);

	std::string makeSafe(std::string& name);
	bool checkPNGorJPGImageExsists(std::string fileName);

public:
	/**
		ctor
	*/
	MusicMissingImageContentFinder(DatabaseTables::Database* databaseHandle);

	/**
		dtor
	*/
	~MusicMissingImageContentFinder();

	bool searchDBforMissingArtistThumbImage(std::string& artistName, int& artistID);
	bool searchDBforMissingArtistImage(std::string& artistName, int& artistID);
	bool searchDBforMissingAlbumImage(std::string& albumName,std::string& artistName, int& albumID);

	void setImageContentURL(std::string newURL){this->imageContentURL = newURL;}

};




}
}


#endif



