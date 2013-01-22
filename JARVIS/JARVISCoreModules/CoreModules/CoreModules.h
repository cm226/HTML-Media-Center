/*
 * CoreModules.h
 *
 *  Created on: Sep 22, 2012
 *      Author: craig
 */

#ifndef COREMODULES_H_
#define COREMODULES_H_

#include "HTMLRendere/HTMLRendere.h"
#include "EventModel/EventModel.h"
#include "Comms/Comms.h"
#include "Database/Database.h"
#include "exportMacros.h"


class DLLCORE_API CoreModules {
private:
	DatabaseTables::Database* databasecon;
	Comms comms;

public:
	CoreModules();
	virtual ~CoreModules();

	DatabaseTables::Database* getDatabaseConnection();
	CommsNS::IComms* getComms();

};

#endif /* COREMODULES_H_ */
