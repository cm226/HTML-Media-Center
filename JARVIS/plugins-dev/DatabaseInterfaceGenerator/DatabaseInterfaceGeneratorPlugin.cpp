/*
 * DatabaseInterfaceGeneratorPlugin.cpp
 *
 *  Created on: 15 May 2013
 *      Author: craig
 */

#include "DatabaseInterfaceGeneratorPlugin.h"
#include "../../JARVISCoreModules/CoreModules/HTMLRendere/Elements/FileUpload.h"
#include "../../JARVISCoreModules/CoreModules/config.h"

#include "InterfaceGenerator/SQLWriter.h"
#include "InterfaceGenerator/SQLParser.h"

#include <boost/bind.hpp>
#include <boost/filesystem.hpp>

DatabaseInterfaceGeneratorPlugin::DatabaseInterfaceGeneratorPlugin(CoreModules* cm) : Plugin(cm)
{
	boost::function2<bool ,Page*,PageCallbackContext* > f = boost::bind(&DatabaseInterfaceGeneratorPlugin::fileUploaded,this, _1, _2);
	this->fileUploadedHandle = this->subscribeHTMLCallback(f);
	this->myGroup = PROG;

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


std::string DatabaseInterfaceGeneratorPlugin::getTempLocation()
{
	std::string tempLocation(TEMPLOC);
	return tempLocation.append("\\DatabaseInterfaceGen");
}

std::string DatabaseInterfaceGeneratorPlugin::clearTempLocation()
{
	std::string tempLocation = this->getTempLocation();

	if(!boost::filesystem::exists(tempLocation))
		boost::filesystem::create_directory(tempLocation);

	boost::filesystem::remove_all(tempLocation);

	return tempLocation;
}

bool DatabaseInterfaceGeneratorPlugin::fileUploaded(Page* page, PageCallbackContext* context)
{
	std::vector<std::string> aditionalContext = context->getAdditionalContext();
	std::string fileName = getFilenameFromContext(aditionalContext);
	std::list<Table> parsedTables;

	SQLParser parser(fileName);
	SQLWriter writer;
	
	parser.getTables(parsedTables);

	this->clearTempLocation();

	for(std::list<Table>::iterator tableIt = parsedTables.begin(); tableIt != parsedTables.end(); tableIt ++)
		writer.writeTable(&(*tableIt), this->getTempLocation());


	return true;
}

std::string DatabaseInterfaceGeneratorPlugin::getFilenameFromContext(std::vector<std::string>& context)
{
	if(context.size() < 1)
	{
		ErrorLogger::logError("Database interface gen: Fileupload dosent contain the file location");
		return "";
	}

	return context[0];
}

void DatabaseInterfaceGeneratorPlugin::buildDownloadPage(Page* p)
{

}


const char* DatabaseInterfaceGeneratorPlugin::pluginName()
{
	return "Database Interface Generator";
}

