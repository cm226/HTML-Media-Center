/*
 * MediaImagesPlugin.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#include "MediaImagesPlugin.h"
#include <iostream>

#include "../../JARVISCoreModules/CoreModules/Database/Database.h"
#include "../../JARVISCoreModules/CoreModules/Database/Tables/Movie/Movie/Movie.h"
#include "../../JARVISCoreModules/CoreModules/config.h"
#include "../../JARVISCoreModules/CoreModules/Errors/ErrorLogger.h"

MediaImagesPlugin::MediaImagesPlugin(CoreModules* framework) : Plugin(framework)
{
	this->name = "Media Images";
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
	/*Form* chooseMediaForm = new Form("mediaForm");
	FormSubmit* submitFormBtt = new FormSubmit("find");

	for(int i = 0; i < 5; i++)
	{
		Lable* l = new Lable("Image"+i);
		l->setText("Image"+i);

		chooseMediaForm->addElement(l);
	}
	chooseMediaForm->addElement(submitFormBtt);
	page->addElement(chooseMediaForm);*/

	std::string imgURL = "http://www.scifispace.com/lotr_poster.jpg";
	std::string ext = imgURL.substr(imgURL.rfind('.',imgURL.length()-1));

	DatabaseTables::Movie movie;
	DatabaseTables::UpdateQuery updateq(&movie);

	this->getUnallocatedMovie(movie);

	std::string thumbName = "lotr"+ext;
	bool downloaded = this->downloadAndCopyImage(imgURL,thumbName);
	if(downloaded)
	{
		movie.thumb->setValue(&thumbName);
		if(!this->coreMod->getDatabaseConnection()->runQuery(&updateq))
		{
			ErrorLogger::logError("updateing Movie: "+movie.name->getStrValue()+" Failed ");
			return false;
		}

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

const char* MediaImagesPlugin::pluginName()
{
	return this->name.c_str();
}
