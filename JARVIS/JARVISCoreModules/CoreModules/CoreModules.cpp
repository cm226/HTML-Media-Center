/*
 * CoreModules.cpp
 *
 *  Created on: Sep 22, 2012
 *      Author: craig
 */

#include "CoreModules.h"

#include <iostream>
#include "config.h"
#include "../../ErrorLogger/Errors/ErrorLogger.h"
#include "Comms/Comms.h"


struct CoreModules::privateMembers
{
	DatabaseTables::Database* databasecon;
	Comms comms;
	MediaStreamer mediaStreamer;
	TaskList taskList;
	FileSystem filesystem;
};

CoreModules::CoreModules():members(new privateMembers())
{
	this->members->databasecon = NULL;
	ErrorLogger::logInfo("Core Modules Loaded");
}

CoreModules::CoreModules(DatabaseTables::Database* databaseOverride):members(new privateMembers())
{
	this->members->databasecon = databaseOverride;
	ErrorLogger::logInfo("Core Modules Loaded");
}

CoreModules::~CoreModules()
{
	if(this->members->databasecon != NULL)
	{
		delete this->members->databasecon;
		this->members->databasecon = NULL;
	}

}


DatabaseTables::Database* CoreModules::getDatabaseConnection()
{
	if(this->members->databasecon == NULL)
	{
		this->members->databasecon = new DatabaseTables::Database();
		auto config = Config::GetInstance();
		this->members->databasecon->Connect(config->DBUser(), config->DBPw(),config->DBName(),"localhost");
	}

	return this->members->databasecon;
}

CommsNS::IComms* CoreModules::getComms()
{
	return &this->members->comms;
}

MediaStreamer& CoreModules::getMediaStreamer()
{
	return this->members->mediaStreamer;
}

TaskList & CoreModules::getTaskList()
{
	return this->members->taskList;
}

FileSystem& CoreModules::getFileSystem()
{
	return this->members->filesystem;
}

