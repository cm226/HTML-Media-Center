/*
 * DatabaseInterfaceGeneratorPlugin.cpp
 *
 *  Created on: 15 May 2013
 *      Author: craig
 */

#include "DatabaseInterfaceGeneratorPlugin.h"
#include "../../JARVISCoreModules/CoreModules/HTMLRendere/Elements/FileUpload.h"

DatabaseInterfaceGeneratorPlugin::DatabaseInterfaceGeneratorPlugin(CoreModules* cm) : Plugin(cm)
{
}

DatabaseInterfaceGeneratorPlugin::~DatabaseInterfaceGeneratorPlugin()
{

}

bool DatabaseInterfaceGeneratorPlugin::whatDoYouLookLike(Page* page)
{
	FileUpload* sqlFileUploader = new FileUpload("sqlFile");
	page->addElement(sqlFileUploader);

	return true;
}
const char* DatabaseInterfaceGeneratorPlugin::pluginName()
{
	return "Database Interface Generator";
}

