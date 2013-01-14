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

#include "Tables/DatabaseTable.h"
#include "Querys/Querys.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

namespace DatabaseTables {

class Database {
private:
	bool connected;
	  sql::Driver *driver;
	  sql::Connection *con;

	  void fillField(IDatabaseTableField* field, sql::ResultSet* results);

public:
	Database();
	virtual ~Database();

	bool Connect(std::string userName, std::string password, std::string DatabaseName, std::string host);

	bool insertRow(DatabaseTable* row);
	bool runQuery(Query* query);
	bool isConnected();
	

};

} /* namespace DatabaseTables */
#endif /* DATABASE_H_ */
