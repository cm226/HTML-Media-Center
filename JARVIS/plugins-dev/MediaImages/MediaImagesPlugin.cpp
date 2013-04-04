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

#include "../../JARVISCoreModules/CoreModules/Errors/ErrorLogger.h"

MediaImagesPlugin::MediaImagesPlugin(CoreModules* framework) : Plugin(framework), movieImageGetter(framework)
{
	this->name = "Media Images";

	boost::function2<bool ,Page*,PageCallbackContext* > f = boost::bind(&MediaImagesPlugin::handleMovieSelected,this, _1, _2);
	this->subscribeHTMLCallback(f, this->movieImageSelected);

	boost::function2<bool ,Page*,PageCallbackContext* > f1 = boost::bind(&MediaImagesPlugin::handleMusicSelected,this, _1, _2);
	this->subscribeHTMLCallback(f1, this->musicISelected);

	boost::function2<bool ,Page*,PageCallbackContext* > f2 = boost::bind(&MediaImagesPlugin::handleTvSelected,this, _1, _2);
	this->subscribeHTMLCallback(f2, this->tvSelected);

	this->movieImageGetter.registerFunctions(this);
	
}

MediaImagesPlugin::~MediaImagesPlugin()
{

}



bool MediaImagesPlugin::whatDoYouLookLike(Page* page)
{
	Lable* movies = new Lable("moviesLbl");
	Lable* music = new Lable("musicLbl");
	Lable* tv = new Lable("tvLbl");

	movies->setText("Movie Images");
	music->setText("Music Images");
	tv->setText("TV Images");

	movies->addOnclickCallbackAttribute(1,this->movieImageSelected,this->name);
	music->addOnclickCallbackAttribute(1,this->musicISelected, this->name);
	tv->addOnclickCallbackAttribute(1, this->tvSelected, this->name);
	
	page->addElement(movies);
	page->addElement(music);
	page->addElement(tv);

	return true;

}


bool MediaImagesPlugin::handleMusicSelected(Page* page, PageCallbackContext* context)
{
	ErrorLogger::logInfo("in music");
	return true;
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
