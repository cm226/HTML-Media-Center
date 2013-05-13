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
#include "Database/Database.h"
#include "exportMacros.h"
#include "Comms/IComms.h"


class DLLCORE_API CoreModules {
private:
	struct privateMembers;
	privateMembers* members;

public:
	CoreModules();
	CoreModules(DatabaseTables::Database* databaseOverride);
	virtual ~CoreModules();

	DatabaseTables::Database* getDatabaseConnection();
	CommsNS::IComms* getComms();

	CoreModules& operator=(const CoreModules&);


};

#endif /* COREMODULES_H_ */
