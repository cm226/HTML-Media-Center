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

bool Database::Connect(
	std::string userName,
	std::string password,
	std::string DatabaseName,
	std::string hostName
) {
	m_mysql = std::shared_ptr<MYSQL>(mysql_init(NULL),
		 [](auto ptr){
			 mysql_close(ptr);
		 }
	);

  	if (!mysql_real_connect(
			m_mysql.get(),
			"127.0.0.1",
			userName.c_str(),
			password.c_str(), 
            DatabaseName.c_str(),
			0,
			"/tmp/mysql.sock", 0)) {

			ErrorLogger::logError(
				std::string("Failed to connect to database with error :") +
				 mysql_error(m_mysql.get()));

			return false;
	}

	this->connected = true;
	return true;
	
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
	std::function<std::shared_ptr<ResultBase>()>& result_factory,
	std::list<std::shared_ptr<ResultBase>>& result_list
) {
	if(this->connected)
	{
		std::string queryStr = query->buildQuery();
		ErrorLogger::logInfo("Running Query on Database: "+queryStr);
		
		if (mysql_real_query(m_mysql.get(), queryStr.c_str(), queryStr.length()) != 0){
			ErrorLogger::logError(
				std::string("Failed to run db query :") +
				 mysql_error(m_mysql.get()));
			return false;
		}
				
		MYSQL_RES *result = mysql_store_result(m_mysql.get());

		std::shared_ptr<ResultWrapper> res_wrapper = 
			std::make_shared<ResultWrapper>(result); 

		while(res_wrapper->next()){
			auto new_result = result_factory();
			result_list.push_back(new_result);
			new_result->ReadNext(res_wrapper);
		}
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
