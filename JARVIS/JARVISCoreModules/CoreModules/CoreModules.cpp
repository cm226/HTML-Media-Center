/*
 * CoreModules.cpp
 *
 *  Created on: Sep 22, 2012
 *      Author: craig
 */

#include "CoreModules.h"

#include <iostream>

CoreModules::CoreModules() {
	std::cout << "cm Loaded" << std::endl;
}

CoreModules::~CoreModules() {
}


DatabaseTables::Database* CoreModules::getDatabaseConnection()
{
	if(this->databasecon == NULL)
	{
		this->databasecon = new DatabaseTables::Database();
		this->databasecon->Connect("root", "root","MediaServer","localhost");
	}

	return this->databasecon;
}

CommsNS::IComms* CoreModules::getComms()
{
	return &this->comms;
}

