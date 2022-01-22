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
	std::shared_ptr<TaskList> taskList;
	std::shared_ptr<Scheduler> scheduler;
	FileSystem filesystem;
	Sensors sensors;
};

CoreModules::CoreModules():members(new privateMembers())
{
	this->members->databasecon = NULL;
	members->scheduler = std::make_shared<Scheduler>();
	members->taskList = std::make_shared<TaskList>();

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

DatabaseTables::Database* CoreModules::getDatabaseWithoutConnect(){
	
	if(this->members->databasecon == NULL)
	{
		this->members->databasecon = new DatabaseTables::Database(
			this->members->taskList
		);
	}

	return this->members->databasecon;
}


DatabaseTables::Database* CoreModules::getDatabaseConnection()
{
	getDatabaseWithoutConnect();

	if(!this->members->databasecon->isConnected()){
		
		auto config = Config::GetInstance();
		this->members->databasecon->Connect(
			config->DBUser(),
			 config->DBPw(),
			 config->DBName(),
			 "db"
		);
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

std::shared_ptr<TaskList> CoreModules::getTaskList()
{
	return this->members->taskList;
}

std::shared_ptr<Scheduler> CoreModules::getScheduler()
{
	return this->members->scheduler;
}

FileSystem& CoreModules::getFileSystem()
{
	return this->members->filesystem;
}

Sensors& CoreModules::getSensors(){
	return this->members->sensors;
}
