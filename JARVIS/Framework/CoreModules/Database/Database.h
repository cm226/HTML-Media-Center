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

#include "Tables/Tables.h"
#include "Querys/Querys.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

namespace DatabaseTables {

class Database {
private:
	  sql::Driver *driver = NULL;
	  sql::Connection *con = NULL;

public:
	Database();
	virtual ~Database();

	bool Connect(std::string userName, std::string password, std::string DatabaseName);

	void insertRow(DatabaseTable* row);
	std::vector<std::vector<DatabaseTable*>> runQuery(Query query);

};

} /* namespace DatabaseTables */
#endif /* DATABASE_H_ */
