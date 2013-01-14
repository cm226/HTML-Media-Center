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
//#include "Database/Database.h"

class CoreModules {
private:
	//DatabaseTables::Database* databasecon = NULL;

public:
	CoreModules();
	virtual ~CoreModules();

	//DatabaseTables::Database* getDatabaseConnection();
};

#endif /* COREMODULES_H_ */
