/*
 * Database.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <string>
#include <vector>
#include <list>
#include <functional>
#include <memory>

#include "Tables/DatabaseTable.h"
#include "Querys/Querys.h"
#include "Results/ResultTypes.h"
#include "../exportMacros.h"

#include <mysql.h>


class TaskList;

namespace DatabaseTables {

class DLLCORE_API Database {
private:
	bool connected;

	std::string m_userName;
	std::string m_password;
	std::string m_DatabaseName;
	std::string m_hostName;

public:
	Database(std::shared_ptr<TaskList> tasklist);
	virtual ~Database();

	bool Connect(std::string userName, std::string password, std::string DatabaseName, std::string host);

	bool insertRow(DatabaseTable* row);
	bool runQuery(
		IQuery* query,
		ResultWrapper& result_list
	);
	bool isConnected();
	
	void startMysqlServer();
	void stopMysqlServer();

private: 
	bool ConnectInternal(
		std::shared_ptr<MYSQL> mysql_con
	);

	bool IsSeriviceIsRunning();


private:

	std::shared_ptr<TaskList> m_task_list;
	bool m_service_running;

};

} /* namespace DatabaseTables */
#endif /* DATABASE_H_ */
