/*
 * Database.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#include "Database.h"
#include "ResultWrapper.h"
#include <stdio.h>


namespace DatabaseTables {

Database::Database() {

	 this->driver = get_driver_instance();
	 this->con = NULL;
}

Database::~Database() {
	delete con;
}

bool Database::Connect(std::string userName, std::string password, std::string DatabaseName, std::string hostName)
{
	if(con != NULL)
		delete con;
	try
	{
		con = driver->connect(hostName, userName, password);
		con->setSchema(DatabaseName);
	}
	catch(sql::SQLException &e)
	{
		this->connected = false;
		return false;
	}
	this->connected = true;
	return true;
	
}

void Database::insertRow(DatabaseTable* row)
{
	sql::Statement *stmt = con->createStatement();
	stmt->execute(row->getInsertQuery());
	delete stmt;

}
bool Database::runQuery(Query* query)
{
	if(this->connected)
	{
		try
		{
			std::string queryStr = query->buildQuery();
			sql::PreparedStatement *pstmt = con->prepareStatement(queryStr);
			sql::ResultSet *res = pstmt->executeQuery();
			ResultWrapper* resWrapper = new ResultWrapper(res); 
			query->setQueryResult(resWrapper);
	
			delete pstmt;
			return true;
		}
		catch(sql::SQLException e)
		{
			std::string error = e.getSQLState();
			std::cout << "Query error "<<error << std::endl;
			return false;
		}
	}
	else
		return false;
}

bool Database::isConnected()
{
	return this->connected;
}

} /* namespace DatabaseTables */
