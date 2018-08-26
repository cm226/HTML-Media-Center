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

#include "Tables/DatabaseTable.h"
#include "Querys/Querys.h"
#include "Results/ResultTypes.h"
#include "../exportMacros.h"

#include <mysql.h>


namespace DatabaseTables {

class DLLCORE_API Database {
private:
	bool connected;
	std::shared_ptr<MYSQL> m_mysql;

public:
	Database();
	virtual ~Database();

	bool Connect(std::string userName, std::string password, std::string DatabaseName, std::string host);

	bool insertRow(DatabaseTable* row);
	bool runQuery(
		IQuery* query,
		std::function<std::shared_ptr<ResultBase>()>& result_factory,
		std::list<std::shared_ptr<ResultBase>>& result_list
	);
	bool isConnected();
	

};

} /* namespace DatabaseTables */
#endif /* DATABASE_H_ */
