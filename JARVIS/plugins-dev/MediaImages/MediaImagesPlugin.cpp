/*
 * MediaImagesPlugin.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#include "MediaImagesPlugin.h"
#include <iostream>


MediaImagesPlugin::MediaImagesPlugin(CoreModules* framework) : Plugin(framework)
{
	this->name = "Media Images";
}

MediaImagesPlugin::~MediaImagesPlugin()
{

}

bool MediaImagesPlugin::whatDoYouLookLike(Page* page)
{
	Form* chooseMediaForm = new Form("mediaForm");
	FormSubmit* submitFormBtt = new FormSubmit("find");

	for(int i = 0; i < 5; i++)
	{
		Lable* l = new Lable("Image"+i);
		l->setText("Image"+i);

		chooseMediaForm->addElement(l);
	}
	chooseMediaForm->addElement(submitFormBtt);
	page->addElement(chooseMediaForm);
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
