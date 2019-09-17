/*
 * Database.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#include "Database.h"
#include "ResultWrapper.h"
#include "../../../ErrorLogger/Errors/ErrorLogger.h"
#include <stdio.h>
#include <sstream>


namespace DatabaseTables {

Database::Database() {

}

Database::~Database() {
	
}

bool Database::ConnectInternal(
	std::shared_ptr<MYSQL> mysql_con
){
	if (!mysql_real_connect(
			mysql_con.get(),
			"127.0.0.1",
			m_userName.c_str(),
			m_password.c_str(), 
            m_DatabaseName.c_str(),
			0,
			"/tmp/mysql.sock", 0)) {

			ErrorLogger::logError(
				std::string("Failed to connect to database with error :") +
				 mysql_error(mysql_con.get()));

			return false;
	}

	return true;


}

bool Database::Connect(
	std::string userName,
	std::string password,
	std::string DatabaseName,
	std::string hostName
) {
	// This function just tests the credentials supplied 
	// and stores if we have had valid ones
	std::shared_ptr<MYSQL> mysql_conn = std::shared_ptr<MYSQL>(mysql_init(NULL),
		 [](auto ptr){
			 mysql_close(ptr);
		 }
	);

	m_userName = userName;
	m_password = password;
	m_DatabaseName = DatabaseName;
	m_hostName = hostName;

	if(ConnectInternal(mysql_conn)){
		this->connected = true;
		return true;
	}
	
	return false;
	
}

bool Database::insertRow(DatabaseTable* row)
{
	// try
	// {
	// 	sql::Statement *stmt = NULL;
	// 	sql::PreparedStatement* pStmt = NULL;

	// 	DatabaseTables::IDatabaseTableField* pk = row->getPrimaryKey();
		
	// 		bool sucessfull = true;
	// 		std::string q = row->getInsertQuery();
	// 		stmt = con->createStatement();
	// 		stmt->execute(q);
	// 		delete stmt;
	// 		stmt = NULL;
			
	// 		if(pk != NULL)
	// 		{

	// 			std::string getAutoIncRow = "SELECT MAX("+pk->getName()+") AS "+pk->fieldName()+" FROM "+pk->ownerName();
	// 			pStmt = con->prepareStatement(getAutoIncRow);
	// 			sql::ResultSet* res = pStmt->executeQuery();
	// 			ResultWrapper resWrapper(res);
	// 			if(resWrapper.next())
	// 				pk->takeValue(&resWrapper);
	// 			else
	// 				sucessfull = false;

	// 			delete pStmt;
	// 			pStmt = NULL;

	// 			return sucessfull;
	// 		}
	// 	else
	// 	{
	// 		if(stmt != NULL) delete stmt;
	// 		if(pStmt != NULL) delete pStmt;
	// 		return true;
	// 		#ifdef _DEBUG
	// 		std::cout << "Warning that table aint got a pk" << std::endl;
	// 		#endif
	// 	}
	// }
	// catch(sql::SQLException& e)
	// {
	// 	std::cout << "Query error "<< e.getSQLState() << std::endl;
	// 	return false;
	// }
	
	return false;


}
bool Database::runQuery(
	IQuery* query,
	ResultWrapper& results
) {
	if(this->connected)
	{

		std::shared_ptr<MYSQL> mysql_conn = std::shared_ptr<MYSQL>(mysql_init(NULL),
		 [](auto ptr){
			 mysql_close(ptr);
		 }
		);

		if(!ConnectInternal(mysql_conn)){
			std::string("Failed to connect to db :") +
				 mysql_error(mysql_conn.get());
		}

		std::string queryStr = query->buildQuery();
		ErrorLogger::logInfo("Running Query on Database: "+queryStr);
		
		if (mysql_real_query(mysql_conn.get(), queryStr.c_str(), queryStr.length()) != 0){
			ErrorLogger::logError(
				std::string("Failed to run db query :") +
				 mysql_error(mysql_conn.get()));
			return false;
		}
				
		MYSQL_RES *result = mysql_store_result(mysql_conn.get());
		results.SetResults(result);

		return true;

	}
	else
		return false;
}

bool Database::isConnected()
{
	return this->connected;
}

} /* namespace DatabaseTables */