/*
 * MediaImagesPlugin.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#include "MediaImagesPlugin.h"


MediaImagesPlugin::MediaImagesPlugin(CoreModules* framework) : Plugin(framework)
{
	this->name = "Media Images";
}

MediaImagesPlugin::~MediaImagesPlugin()
{

}

bool MediaImagesPlugin::whatDoYouLookLike(Page* page)
{
	/*std::string googleImgURL = "https://ajax.googleapis.com/ajax/services/search/images?v=1.0&q=fuzzy%20monkey";
	std::string jsonReply;


	CommsNS::IJSONRequest* req = this->coreMod->getComms()->createJSONRequest();

	req->requestURL(googleImgURL);
	req->makeRequest(jsonReply);

	std::cout << "reply: " << jsonReply << std::endl;
	delete req;*/

	std::cout << "MediaImages";


	return true;
}

const char* MediaImagesPlugin::pluginName()
{
	return this->name.c_str();
}
