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
#include <algorithm>

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
	
	this->imgURLs.clear();
	this->movieName = "";

	bool anyMoviesLeft = this->getUnallocatedMovie(movie);
	if(!anyMoviesLeft)
	{
		Lable* l = new Lable("resLable");
		l->setText("No Unalocated Movies Left");
		page->addElement(l);
		return true;
	}
	this->doGoogleSearch(imgURLs,movie.name->getStrValue() +" Poster");

	this->movieID = movie.movieID->getValue();
	this->movieName = movie.name->getStrValue();
	movieNameLable->setText("For Movie: "+movie.name->getStrValue());
	page->addElement(movieNameLable);

	std::string onClickAttributeStart = "onClick=\"window.location = '../pluginInteraction/";
	std::vector<std::string>::iterator resultIt = this->imgURLs.begin();
	int i =0;
	for(resultIt; resultIt!= this->imgURLs.end(); resultIt++)
	{
		HTMLImage* image = new HTMLImage("img",*resultIt);
		std::stringstream attributeStream ;
		attributeStream << onClickAttributeStart;
		attributeStream << this->movieImageSelected << "/" << this->name <<  "/" << i << "'\"";
		image->addAttribute(attributeStream.str());
		chooseMediaForm->addElement(image);
		i++;
	}

	chooseMediaForm->addElement(submitFormBtt);
	page->addElement(chooseMediaForm);


	return true;
}

bool MediaImagesPlugin::handleImageSelected(int movieID,std::string tbhumbName, std::string imgURL)
{	
	std::string::size_type pos = imgURL.rfind('.',imgURL.length()-1);
	if(pos > imgURL.length() || pos == std::string::npos)
	{
		ErrorLogger::logError("Bad URL returned from image Search :" + imgURL);
		return false;
	}

	std::string ext = imgURL.substr(pos);
	std::string thumbName = tbhumbName+ext;
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
	movieID << movID;

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
	std::string queryStriped = query;
	std::string::iterator queryStripedIt;
	for(queryStripedIt = queryStriped.begin(); queryStripedIt != queryStriped.end(); queryStripedIt++)
	{
		char c = (*queryStripedIt);
		if(c == ' ')
			queryStriped.replace(queryStripedIt, queryStripedIt+1, "%20");
	}

	std::string googleImgURL = "http://ajax.googleapis.com/ajax/services/search/images?v=1.0&q="+queryStriped;
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
	std::vector<std::string> contextAttributes = context->getAdditionalContext();
	int numContextAttributes = contextAttributes.size();

	if(numContextAttributes ==0)
	{
		ErrorLogger::logError("Media Images Plugin: not enough data in context array, missing the selected Image value");
		std::cout << "Not Enough data see JARVIS log for more";
		return false;
	}

	if(numContextAttributes > 1)
	{
		ErrorLogger::logWarn("Media Images Plugin: additional arguments in context string");
	}

	std::string imageIndex = *contextAttributes.begin();
	std::stringstream ss;
	ss << imageIndex;
	int index;
	ss >> index;

	std::string imageURL = this->imgURLs[index];

	bool worked = handleImageSelected(this->movieID, this->movieName,imageURL);
	if(!worked)
	{
		ErrorLogger::logError("Unable to process selected Image");
		return false;
	}

	Lable* allWentWell = new Lable("Image Set, all is well");
	Hyperlink* hyperlink = new Hyperlink("nextLink", "localhost/blargh","Next Movie");

	page->addElement(allWentWell);
	page->addElement(hyperlink);


	return true;
}

const char* MediaImagesPlugin::pluginName()
{
	return this->name.c_str();
}
