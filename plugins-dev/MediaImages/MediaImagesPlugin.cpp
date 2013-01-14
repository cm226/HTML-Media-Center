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


	return true;
}

const char* MediaImagesPlugin::pluginName()
{
	return this->name.c_str();
}
