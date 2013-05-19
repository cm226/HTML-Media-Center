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
	static const CALLBACk_HANDLE ARTIST_THUMBNAIL_IMG = 21;
	static const CALLBACk_HANDLE ARTIST_IMG = 22;
	static const CALLBACk_HANDLE ALBUM_IMG = 23;

	ImageGetter imgGetter;
	imagegetters::music::MusicMissingImageContentFinder missingContentFinder;
	std::string registereName;

	void loadArtistThumbImagePage(Page* p, std::string artistName, int artistID);
	void loadArtistImagePage(Page* p, std::string artistName, int artistID);
	void loadAlbumImagePage(Page* p, std::string artistName, std::string albumName, int albumID);
	void loadNoMissingContentPage(Page* p);

	HTMLImage* createHTMLImageElement(CALLBACk_HANDLE handel, int imageIndex, int artistID, std::string imageURL);

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

