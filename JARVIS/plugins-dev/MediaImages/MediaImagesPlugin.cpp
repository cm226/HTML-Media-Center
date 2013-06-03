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
#include <boost/bind.hpp>
#include <algorithm>

#include "../../JARVISCoreModules/CoreModules/Errors/ErrorLogger.h"

MediaImagesPlugin::MediaImagesPlugin(CoreModules* framework) : Plugin(framework), 
																movieImageGetter(framework),
																musicImageGetter(framework)
{
	this->name = "Media Images";
	this->myGroup = CONTENT_GEN;

	boost::function2<bool ,Page*,PageCallbackContext* > f = boost::bind(&MediaImagesPlugin::handleMovieSelected,this, _1, _2);
	this->movieImageSelected = this->subscribeHTMLCallback(f);

	boost::function2<bool ,Page*,PageCallbackContext* > f1 = boost::bind(&MediaImagesPlugin::handleMusicSelected,this, _1, _2);
	 this->musicISelected = this->subscribeHTMLCallback(f1);

	boost::function2<bool ,Page*,PageCallbackContext* > f2 = boost::bind(&MediaImagesPlugin::handleTvSelected,this, _1, _2);
	this->tvSelected = this->subscribeHTMLCallback(f2);

	this->movieImageGetter.registerFunctions(this);
	this->musicImageGetter.registerFunctions(this);
	
}

MediaImagesPlugin::~MediaImagesPlugin()
{

}

bool MediaImagesPlugin::whatDoYouLookLike(Page* page)
{
	
	coremodules::htmlrendere::elements::menulist::MenuList* mainMenu = new coremodules::htmlrendere::elements::menulist::MenuList("MainMenu");
	
	mainMenu->addItem("Movie Images",1,this->movieImageSelected,this->name);
	mainMenu->addItem("Music Images",1,this->musicISelected,this->name);
	mainMenu->addItem("TV Images",1,this->tvSelected,this->name);

	page->addElement(mainMenu);
	return true;

}


bool MediaImagesPlugin::handleMusicSelected(Page* page, PageCallbackContext* context)
{
	return this->musicImageGetter.handleMusicSelected(page,context);
}
bool MediaImagesPlugin::handleTvSelected(Page* page, PageCallbackContext* context)
{
	ErrorLogger::logInfo("in tv");
	return true;
}

bool MediaImagesPlugin::handleMovieSelected(Page* page, PageCallbackContext* context)
{
	return this->movieImageGetter.handleMovieSelected(page,context);
}

const char* MediaImagesPlugin::pluginName()
{
	return this->name.c_str();
}
