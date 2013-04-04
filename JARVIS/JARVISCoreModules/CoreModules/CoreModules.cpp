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

CoreModules::CoreModules() {
	
	this->databasecon = NULL;

	ErrorLogger::logInfo("Core Modules Loaded");
}

CoreModules::~CoreModules() {
}


DatabaseTables::Database* CoreModules::getDatabaseConnection()
{
	if(this->databasecon == NULL)
	{
		this->databasecon = new DatabaseTables::Database();
		this->databasecon->Connect(DATABSEUSER, DATABASEPASSWORD,DATABASENAME,"localhost");
	}

	return this->databasecon;
}

CommsNS::IComms* CoreModules::getComms()
{
	return &this->comms;
}

