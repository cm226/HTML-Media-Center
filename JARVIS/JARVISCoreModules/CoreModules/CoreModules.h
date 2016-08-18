/*
 * CoreModules.h
 *
 *  Created on: Sep 22, 2012
 *      Author: craig
 */

#ifndef COREMODULES_H_
#define COREMODULES_H_


#include <boost/shared_ptr.hpp>
#include "HTMLRendere/HTMLRendere.h"
#include "EventModel/EventModel.h"
#include "Database/Database.h"
#include "exportMacros.h"

#include "Comms/IComms.h"
#include "../../MediaStreaming/MediaStreaming/MediaStreamer.h"
#include "TaskList/TaskList.h"
#include "Files/Files.h"


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
	CommsNS::IComms* getComms();
	MediaStreamer& getMediaStreamer();
	TaskList& getTaskList();
	FileSystem& getFileSystem();
	



};

#endif /* COREMODULES_H_ */
