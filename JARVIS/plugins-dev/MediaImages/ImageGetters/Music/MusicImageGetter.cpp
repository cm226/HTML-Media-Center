#include "MusicImageGetter.h"
#include <sstream>
#include <boost/bind.hpp>
#include "../../../../JARVISCoreModules/CoreModules/Database/Tables/Artist/Artist.h"

MusicImageGetter::MusicImageGetter(CoreModules* cm) : imgGetter(cm), missingContentFinder(cm->getDatabaseConnection())
{
	this->cm = cm;
}


MusicImageGetter::~MusicImageGetter(void)
{
}

void MusicImageGetter::registerFunctions(Plugin* registerer)
{
	boost::function2<bool ,Page*,PageCallbackContext* > artistThumbSelectedFunc = boost::bind(&MusicImageGetter::onArtistThumbSelected,this, _1, _2);
	this->ARTIST_THUMBNAIL_IMG = registerer->subscribeHTMLCallback(artistThumbSelectedFunc);

	boost::function2<bool ,Page*,PageCallbackContext* > artistSelectedFunc = boost::bind(&MusicImageGetter::onArtistSelected,this, _1, _2);
	this->ARTIST_IMG = registerer->subscribeHTMLCallback(artistSelectedFunc);

	boost::function2<bool ,Page*,PageCallbackContext* > albumSelectedFunc = boost::bind(&MusicImageGetter::onAlbumSelected,this, _1, _2);
	this->ALBUM_IMG = registerer->subscribeHTMLCallback(albumSelectedFunc);


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
	googleImageResults.clear();
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
	googleImageResults.clear();
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
	googleImageResults.clear();
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


bool MusicImageGetter::assertContextArguments(std::vector<std::string>& contextarguments)
{
	int numContextAttributes = contextarguments.size();

	if(numContextAttributes <2)
	{
		ErrorLogger::logError("Media Images Plugin: not enough data in context array, missing the selected Image value");
		std::cout << "Not Enough data see JARVIS log for more";
		return false;
	}

	if(numContextAttributes > 2)
	{
		ErrorLogger::logWarn("Media Images Plugin: additional arguments in context string");
	}

	return true;
}

std::string MusicImageGetter::getArtistNameFromID(int artistID)
{
	DatabaseTables::Query artistNameQuery;
	DatabaseTables::Artist::Artist artist;
	std::stringstream artistIDss;
	std::string artistIDStr;
	artistIDss << artistID;
	artistIDStr = artistIDss.str();
	DatabaseTables::Equals equalsConstrint(artist.artistID, artistIDStr);
	
	artistNameQuery.addSelectItem(&artist);
	artistNameQuery.addConstraint(&equalsConstrint);

	DatabaseTables::Database *db = this->cm->getDatabaseConnection();
	bool worked = db->runQuery((DatabaseTables::IQuery*)&artistNameQuery);
	if(!worked)
	{
		ErrorLogger::logError("Media Image Getter: Unable to get move entry in database for movie ID: "+artistIDStr);
		return "";
	}

	if(!artistNameQuery.nextLine())
		return "";

	std::string artistName = artist.artistName->getValue();
	return artistName;

}



int MusicImageGetter::readImageIndex(std::vector<std::string>& contextarguments)
{
	return this->imgGetter.readInt(contextarguments,0);
}
int MusicImageGetter::readArtistID(std::vector<std::string>& contextarguments)
{
	return this->imgGetter.readInt(contextarguments,1);
}


bool MusicImageGetter::onArtistThumbSelected(Page* page, PageCallbackContext* context)
{
	std::vector<std::string> contextArgs = context->getAdditionalContext();
	if(!assertContextArguments(contextArgs))
		return false;

	int imageIndex = this->readImageIndex(contextArgs);
	int ArtistID = this->readArtistID(contextArgs);

	if(imageIndex <= -1 || ArtistID <= -1) return false;
	if((unsigned int)imageIndex > this->googleImageResults.size())
	{
		ErrorLogger::logError("Image Set Value out of range");
		return false;
	}

	std::string imageURL = this->googleImageResults.at(imageIndex);

	bool worked = handleArtistThumbImageSelected(ArtistID, this->getArtistNameFromID(ArtistID),imageURL);
	
	if(!worked)
	{
		ErrorLogger::logError("Unable to process selected Image");
		return false;
	}

	Lable* l = new Lable("we");
	l->setText("gd shit sone");
	page->addElement(l);
	return true;
}



bool MusicImageGetter::handleArtistThumbImageSelected(int artistID,std::string tbhumbName, std::string imgURL)
{	
    std::string::size_type pos = imgURL.rfind('.',imgURL.length()-1);
	if(pos > imgURL.length() || pos == std::string::npos)
	{
		ErrorLogger::logError("Bad URL returned from image Search :" + imgURL);
		return false;
	}

	std::string ext = imgURL.substr(pos);
	std::string thumbName = tbhumbName+ext;
	std::string::iterator thumbNameIt;
	std::stringstream thumbNameStriped;
	for(thumbNameIt = thumbName.begin(); thumbNameIt != thumbName.end(); thumbNameIt++)
	{
		char c = *thumbNameIt;
		if(c == ' ' || c == '/' || c == '\\')
			thumbNameStriped << '.';
		else
		thumbNameStriped << c;
	}

	bool downloaded = this->imgGetter.downloadAndCopyImageToPublicFolder(imgURL,"\\img\\Movie\\Thumbs\\",thumbNameStriped.str(),200,280);
	
	return false;

}




bool MusicImageGetter::onArtistSelected(Page* page, PageCallbackContext* context)
{
	return true;
}
bool MusicImageGetter::onAlbumSelected(Page* page, PageCallbackContext* context)
{
	return true;
}
