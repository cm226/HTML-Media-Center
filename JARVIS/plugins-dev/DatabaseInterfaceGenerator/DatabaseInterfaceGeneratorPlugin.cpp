/*
 * DatabaseInterfaceGeneratorPlugin.cpp
 *
 *  Created on: 15 May 2013
 *      Author: craig
 */

#include "DatabaseInterfaceGeneratorPlugin.h"
#include "../../JARVISCoreModules/CoreModules/HTMLRendere/Elements/FileUpload.h"
#include <boost\bind.hpp>

DatabaseInterfaceGeneratorPlugin::DatabaseInterfaceGeneratorPlugin(CoreModules* cm) : Plugin(cm)
{
	boost::function2<bool ,Page*,PageCallbackContext* > f = boost::bind(&DatabaseInterfaceGeneratorPlugin::fileUploaded,this, _1, _2);
	this->fileUploadedHandle = this->subscribeHTMLCallback(f);

}

DatabaseInterfaceGeneratorPlugin::~DatabaseInterfaceGeneratorPlugin()
{

}

bool DatabaseInterfaceGeneratorPlugin::whatDoYouLookLike(Page* page)
{
	FileUpload* sqlFileUploader = new FileUpload("sqlFile",1,this->fileUploadedHandle,this->pluginName());
	page->addElement(sqlFileUploader);

	return true;
}

bool DatabaseInterfaceGeneratorPlugin::fileUploaded(Page* page, PageCallbackContext* context)
{
	return true;
}

const char* DatabaseInterfaceGeneratorPlugin::pluginName()
{
	return "Database Interface Generator";
}

