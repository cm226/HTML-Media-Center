/*
 * Database.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#include "Database.h"


namespace DatabaseTables {

Database::Database() {

	 this->driver = get_driver_instance();

}

Database::~Database() {
	delete con;
}

bool Database::Connect(std::string userName, std::string password, std::string DatabaseName)
{
	if(con != NULL)
		delete con;
	try
	{
		con = driver->connect("tcp://127.0.0.1:3306", userName, password);
		con->setSchema(DatabaseName);
	}
	catch(sql::SQLException &e)
	{
		return false;
	}
	return true;
}

void Database::insertRow(DatabaseTable* row)
{
	sql::Statement *stmt = con->createStatement();
	stmt->execute(row->getInsertQuery());
	delete stmt;

}
std::vector<std::vector<DatabaseTable*>> Database::runQuery(Query query)
{

	sql::PreparedStatement *pstmt = con->prepareStatement("select * from example");
	sql::ResultSet *res = pstmt->executeQuery();
		while (res->next());
			//res->getInt("id") "  "<<res->getString("data");
	delete res;
	delete pstmt;

	return NULL;
}

} /* namespace DatabaseTables */
