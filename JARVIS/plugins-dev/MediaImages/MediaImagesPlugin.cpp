/*
 * MediaImagesPlugin.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#include "MediaImagesPlugin.h"
#include <iostream>
#include <sstream>
#include <functional>
#include <boost\bind.hpp>

#include "../../JARVISCoreModules/CoreModules/Database/Database.h"
#include "../../JARVISCoreModules/CoreModules/Database/Tables/Movie/Movie/Movie.h"
#include "../../JARVISCoreModules/CoreModules/config.h"
#include "../../JARVISCoreModules/CoreModules/Errors/ErrorLogger.h"

MediaImagesPlugin::MediaImagesPlugin(CoreModules* framework) : Plugin(framework)
{
	this->name = "Media Images";

	boost::function2<bool ,Page*,PageCallbackContext* > f = boost::bind(&MediaImagesPlugin::handleMovieSelected,this, _1, _2);
	this->subscribeHTMLCallback(f, this->movieImageSelected);
	
}

MediaImagesPlugin::~MediaImagesPlugin()
{

}

bool MediaImagesPlugin::getUnallocatedMovie(DatabaseTables::Movie& movie)
{
	DatabaseTables::Query unallocatedMovie;

	DatabaseTables::IDatabaseTableField* movieThumb = movie.thumb;
	DatabaseTables::Equals urlThumConstrint(movieThumb,"");
	DatabaseTables::Descriptors::Limit limit("1");

	unallocatedMovie.addSelectItem(&movie);
	unallocatedMovie.addConstraint(&urlThumConstrint);

	unallocatedMovie.addDescriptor(&limit);

	DatabaseTables::Database *db = this->coreMod->getDatabaseConnection();
	db->runQuery((DatabaseTables::IQuery*)&unallocatedMovie);

	if(!unallocatedMovie.nextLine()) // should only be 1 result 
		return false;

	return true;

}

bool MediaImagesPlugin::whatDoYouLookLike(Page* page)
{
	DatabaseTables::Movie movie;
	Form* chooseMediaForm = new Form("mediaForm");
	FormSubmit* submitFormBtt = new FormSubmit("find");
	Lable* movieNameLable = new Lable("MovieName");

	std::string imgURLs[4] = {"http://www.scifispace.com/lotr_poster.jpg","http://www.scifispace.com/lotr_poster.jpg","http://www.scifispace.com/lotr_poster.jpg","http://www.scifispace.com/lotr_poster.jpg"};
	
	this->getUnallocatedMovie(movie);

	movieNameLable->setText("For Movie: "+movie.name->getStrValue());
	page->addElement(movieNameLable);

	std::string onClickAttributeStart = "onClick=\"window.location = '../Plugin/pluginInteraction/";

	for(int i = 0; i < 4; i++)
	{
		HTMLImage* image = new HTMLImage("img",imgURLs[i]);
		std::stringstream attributeStream ;
		attributeStream << onClickAttributeStart;
		attributeStream << this->movieImageSelected << "/" << i;
		image->addAttribute(attributeStream.str());
		chooseMediaForm->addElement(image);
	}

	chooseMediaForm->addElement(submitFormBtt);
	page->addElement(chooseMediaForm);


	return true;
}

bool MediaImagesPlugin::handleImageSelected(int movieID, std::string imgURL)
{	
	std::string::size_type pos = imgURL.rfind('.',imgURL.length()-1);
	if(pos > imgURL.length() || pos == std::string::npos)
	{
		ErrorLogger::logError("Bad URL returned from image Search :" + imgURL);
		return false;
	}

	std::string ext = imgURL.substr(pos);
	std::string thumbName = "lotr"+ext;
	bool downloaded = this->downloadAndCopyImage(imgURL,thumbName);

	if(downloaded)
		return this->notifyDatabaseOfMovieUpdate(movieID,thumbName);
	
	return false;
}

bool MediaImagesPlugin::notifyDatabaseOfMovieUpdate(int movID, std::string thumbName)
{
	std::stringstream movieID;

	DatabaseTables::Movie movie;
	DatabaseTables::Query q;
	DatabaseTables::UpdateQuery updateMovieq(&movie);
	movieID << movieID;

	DatabaseTables::Equals eq(movie.getPrimaryKey(),movieID.str());
	q.addSelectItem(&movie);
	q.addConstraint(&eq);
	this->coreMod->getDatabaseConnection()->runQuery(&q);
		
	if(!q.nextLine())
	{
		ErrorLogger::logError("failed to reterve move with id: "+movieID.str()+" when updateing thumnail");
		return false;
	}

	movie.thumb->setValue(&thumbName);
	if(!this->coreMod->getDatabaseConnection()->runQuery(&updateMovieq))
	{
		ErrorLogger::logError("updateing Movie: "+movie.name->getStrValue()+" Failed ");
		return false;
	}

	return true;
}

bool MediaImagesPlugin::downloadAndCopyImage(std::string const& url, std::string const&  movieName)
{
	std::string pubFolder = HTMLMEDIAPUBLIC;
	if(!this->coreMod->getComms()->downloadFile(url,pubFolder+"\\img\\Movie\\Thumbs\\"+movieName))
	{
		ErrorLogger::logError("Failed to Download Movie Thumb");
		return false;
	}
	return true;
}

void MediaImagesPlugin::doGoogleSearch(std::vector<std::string>& result, std::string const &query)
{
	std::string googleImgURL = "http://ajax.googleapis.com/ajax/services/search/images?v=1.0&q="+query;
	std::string jsonReply;


	CommsNS::IJSONRequest* req = this->coreMod->getComms()->createJSONRequest();

	req->requestURL(googleImgURL);
	req->makeRequest(jsonReply);

	std::string urlMarker = "\"url\":\"";
	std::string::size_type startOfURL = 1;
	std::string::size_type endURL;
	std::string::size_type jsonLength = jsonReply.length();
	std::string::size_type markerLength = urlMarker.length();

	while (true)
	{
		
		startOfURL = jsonReply.find(urlMarker,startOfURL);
		std::string::size_type markerURLLen = startOfURL+markerLength;

		endURL = jsonReply.find("\"",markerURLLen+1);

		if(startOfURL < jsonLength && endURL < jsonLength)
			result.push_back(jsonReply.substr(markerURLLen, endURL-markerURLLen));
		else break;

		startOfURL ++;
	}
	delete req;

}

bool MediaImagesPlugin::handleMovieSelected(Page* page, PageCallbackContext* context)
{
	return false;
}

const char* MediaImagesPlugin::pluginName()
{
	return this->name.c_str();
}
