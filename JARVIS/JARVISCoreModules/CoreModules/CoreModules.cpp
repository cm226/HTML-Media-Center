/*
 * CoreModules.cpp
 *
 *  Created on: Sep 22, 2012
 *      Author: craig
 */

#include "CoreModules.h"

#include <iostream>
#include "config.h"
#include "Errors\ErrorLogger.h"
#include "Comms/Comms.h"


struct CoreModules::privateMembers
{
	DatabaseTables::Database* databasecon;
	Comms comms;
};

CoreModules::CoreModules():members(new privateMembers())
{
	
	this->members->databasecon = NULL;

	ErrorLogger::logInfo("Core Modules Loaded");
}

CoreModules::~CoreModules()
{
	if(this->members->databasecon != NULL)
	{
		delete this->members->databasecon;
		this->members->databasecon = NULL;
	}

	delete this->members;
}

CoreModules& CoreModules::operator=(const CoreModules &other)
{
	*this->members = *(other.members);
	return *this;
}

DatabaseTables::Database* CoreModules::getDatabaseConnection()
{
	if(this->members->databasecon == NULL)
	{
		this->members->databasecon = new DatabaseTables::Database();
		this->members->databasecon->Connect(DATABSEUSER, DATABASEPASSWORD,DATABASENAME,"localhost");
	}

	return this->members->databasecon;
}

CommsNS::IComms* CoreModules::getComms()
{
	return &this->members->comms;
}

