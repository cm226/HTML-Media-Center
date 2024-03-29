/*
 * CoreModules.h
 *
 *  Created on: Sep 22, 2012
 *      Author: craig
 */

#ifndef COREMODULES_H_
#define COREMODULES_H_


#include <boost/shared_ptr.hpp>
#include "Database/Database.h"
#include "exportMacros.h"

#include "Comms/IComms.h"
#include "MediaStreaming/MediaStreaming/MediaStreamer.h"
#include "TaskList/TaskList.h"
#include "TaskList/Scheduler.h"
#include "Files/Files.h"
#include "Sensors/Sensors.h"


class DLLCORE_API CoreModules {
private:
	struct privateMembers;
	#pragma warning( disable : 4251)
	boost::shared_ptr<privateMembers> members;
	#pragma warning( default : 4251)

public:
	CoreModules();
	CoreModules(DatabaseTables::Database* databaseOverride);
	virtual ~CoreModules();

	DatabaseTables::Database* getDatabaseConnection();
	DatabaseTables::Database* getDatabaseWithoutConnect();
	CommsNS::IComms* getComms();
	MediaStreamer& getMediaStreamer();
	std::shared_ptr<TaskList> getTaskList();
	std::shared_ptr<Scheduler> getScheduler();
	FileSystem& getFileSystem();
	Sensors& getSensors();
	



};

#endif /* COREMODULES_H_ */
