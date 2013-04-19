#include "MusicImageGetter.h"
#include <sstream>
#include <boost\bind.hpp>

MusicImageGetter::MusicImageGetter(CoreModules* cm) : imgGetter(cm), missingContentFinder(cm->getDatabaseConnection())
{
}


MusicImageGetter::~MusicImageGetter(void)
{
}

void MusicImageGetter::registerFunctions(Plugin* registerer)
{
	boost::function2<bool ,Page*,PageCallbackContext* > artistThumbSelectedFunc = boost::bind(&MusicImageGetter::onArtistThumbSelected,this, _1, _2);
	registerer->subscribeHTMLCallback(artistThumbSelectedFunc, this->ARTIST_THUMBNAIL_IMG);

	boost::function2<bool ,Page*,PageCallbackContext* > artistSelectedFunc = boost::bind(&MusicImageGetter::onArtistSelected,this, _1, _2);
	registerer->subscribeHTMLCallback(artistSelectedFunc, this->ARTIST_IMG);

	boost::function2<bool ,Page*,PageCallbackContext* > albumSelectedFunc = boost::bind(&MusicImageGetter::onAlbumSelected,this, _1, _2);
	registerer->subscribeHTMLCallback(albumSelectedFunc, this->ALBUM_IMG);


	this->registereName = registerer->pluginName();
}


bool MusicImageGetter::handleMusicSelected(Page* page, PageCallbackContext* context)
{
	std::string artistName;
	std::string albumName;
	int artistID;
	int albumID;

	if(this->missingContentFinder.searchDBforMissingArtistThumbImage(artistName,artistID))
		this->loadArtistThumbImagePage(page,artistName, artistID);

	else if(this->missingContentFinder.searchDBforMissingArtistImage(artistName,artistID))
		this->loadArtistImagePage(page, artistName, artistID);

	else if(this->missingContentFinder.searchDBforMissingAlbumImage(albumName,artistName,albumID))
		this->loadAlbumImagePage(page, artistName, albumName, albumID);

	return true;
}

void MusicImageGetter::loadArtistThumbImagePage(Page* p, std::string aritstName, int artistID)
{
	std::vector<std::string> googleImageResults;
	std::vector<std::string>::iterator imagesIt;
	std::stringstream ss;
	int counter = 0;

	this->imgGetter.doGoogleSearch(googleImageResults,aritstName);

	Lable* pageHeader = new Lable("header");
	pageHeader->setText("Artist Thumbnail Image for: "+aritstName);
	p->addElement(pageHeader);

	ElementList* images = new ElementList("imageResultList");
	
	for(imagesIt = googleImageResults.begin(); imagesIt != googleImageResults.end(); imagesIt++)
	{
		images->addElement(this->createHTMLImageElement(ARTIST_THUMBNAIL_IMG,counter,artistID,*imagesIt));
		counter++;
	}

	p->addElement(images);
}
void MusicImageGetter::loadArtistImagePage(Page* p, std::string aritstName, int artistID)
{
	std::vector<std::string> googleImageResults;
	std::vector<std::string>::iterator imagesIt;
	std::stringstream ss;
	int counter = 0;

	this->imgGetter.doGoogleSearch(googleImageResults,aritstName);

	Lable* pageHeader = new Lable("header");
	pageHeader->setText("Artist Image for: "+aritstName);
	p->addElement(pageHeader);

	ElementList* images = new ElementList("imageResultList");
	
	for(imagesIt = googleImageResults.begin(); imagesIt != googleImageResults.end(); imagesIt++)
	{
		images->addElement(this->createHTMLImageElement(ARTIST_IMG,counter,artistID,*imagesIt));
		counter++;
	}

	p->addElement(images);
}
void MusicImageGetter::loadAlbumImagePage(Page* p, std::string aritstName, std::string albumName,int artistID)
{
	std::vector<std::string> googleImageResults;
	std::vector<std::string>::iterator imagesIt;
	std::stringstream ss;
	int counter = 0;

	this->imgGetter.doGoogleSearch(googleImageResults,aritstName);

	Lable* pageHeader = new Lable("header");
	pageHeader->setText("Album Image for: "+albumName+" by "+aritstName);
	p->addElement(pageHeader);

	ElementList* images = new ElementList("imageResultList");
	
	for(imagesIt = googleImageResults.begin(); imagesIt != googleImageResults.end(); imagesIt++)
	{
		images->addElement(this->createHTMLImageElement(ALBUM_IMG,counter,artistID,*imagesIt));
		counter++;
	}

	p->addElement(images);
}

void MusicImageGetter::loadNoMissingContentPage(Page* p)
{
	Lable* nmcLable = new Lable("nmclable");
	nmcLable->setText("No content missing from Music");

	p->addElement(nmcLable);
}

HTMLImage* MusicImageGetter::createHTMLImageElement(CALLBACk_HANDLE handel, int imageIndex, int artistID, std::string imageURL)
{
	std::stringstream ss;

	std::vector<std::string> args;
	ss << imageIndex;
	args.push_back(ss.str());
	ss.str("");
	ss.clear();
	ss << artistID;
	args.push_back(ss.str());

	HTMLImage* htmlImg = new HTMLImage("img",imageURL);
	htmlImg->addOnclickCallbackAttribute(1,handel,this->registereName,args);

	return htmlImg;
}

bool MusicImageGetter::onArtistThumbSelected(Page* page, PageCallbackContext* context)
{
	return true;
}
bool MusicImageGetter::onArtistSelected(Page* page, PageCallbackContext* context)
{
	return true;
}
bool MusicImageGetter::onAlbumSelected(Page* page, PageCallbackContext* context)
{
	return true;
}