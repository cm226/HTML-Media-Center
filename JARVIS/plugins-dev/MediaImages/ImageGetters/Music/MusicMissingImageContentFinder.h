/*
	Author : Craig Matear
*/
#pragma once
#ifndef IMAGEGETTERS_MUSIC_MUSICMISSINGIMAGECONTENTFINDER_H
#define IMAGEGETTERS_MUSIC_MUSICMISSINGIMAGECONTENTFINDER_H

#include <string>
#include "../../../../JARVISCoreModules/CoreModules/Database/Database.h"
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



