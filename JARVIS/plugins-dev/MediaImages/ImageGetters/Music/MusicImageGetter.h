#pragma once
#ifndef MUSIC_IMAGE_GETTER_H
#define MUSIC_IMAGE_GETTER_H

#include <string>

#include "../IimageContentGetter.h"
#include "../ImageGetter.h"
#include "../../../../JARVIS/Framework/Plugin/Plugin.h"
#include "MusicMissingImageContentFinder.h"


class MusicImageGetter : public imagegetters::IimageContentGetter
{
private:
	CALLBACk_HANDLE ARTIST_THUMBNAIL_IMG;
	CALLBACk_HANDLE ARTIST_IMG;
	CALLBACk_HANDLE ALBUM_IMG;

	CoreModules* cm;
	ImageGetter imgGetter;
	imagegetters::music::MusicMissingImageContentFinder missingContentFinder;
	std::string registereName;
	std::vector<std::string> googleImageResults;

	void loadArtistThumbImagePage(Page* p, std::string artistName, int artistID);
	void loadArtistImagePage(Page* p, std::string artistName, int artistID);
	void loadAlbumImagePage(Page* p, std::string artistName, std::string albumName, int albumID);
	void loadNoMissingContentPage(Page* p);

	HTMLImage* createHTMLImageElement(CALLBACk_HANDLE handel, int imageIndex, int artistID, std::string imageURL);

	bool assertContextArguments(std::vector<std::string>& contextarguments);
	int MusicImageGetter::readImageIndex(std::vector<std::string>& contextarguments);
	int MusicImageGetter::readArtistID(std::vector<std::string>& contextarguments);


	bool handleArtistThumbImageSelected(int artistID,std::string tbhumbName, std::string imgURL);
	std::string getArtistNameFromID(int movieID);

		// callback functions
	bool onArtistThumbSelected(Page* page, PageCallbackContext* context);
	bool onArtistSelected(Page* page, PageCallbackContext* context);
	bool onAlbumSelected(Page* page, PageCallbackContext* context);

public:
	MusicImageGetter(CoreModules* cm);
	virtual ~MusicImageGetter(void);

	void registerFunctions(Plugin* registerer);
	bool handleMusicSelected(Page* page, PageCallbackContext* context);


};

#endif

