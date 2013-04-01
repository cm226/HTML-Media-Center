/*
 * Database.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#include "Database.h"
#include "ResultWrapper.h"
#include "../Errors/ErrorLogger.h"
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

bool Database::insertRow(DatabaseTable* row)
{
	try
	{
		sql::Statement *stmt = NULL;
		sql::PreparedStatement* pStmt = NULL;

		DatabaseTables::IDatabaseTableField* pk = row->getPrimaryKey();
		
			bool sucessfull = true;
			std::string q = row->getInsertQuery();
			stmt = con->createStatement();
			stmt->execute(q);
			delete stmt;
			stmt = NULL;
			
			if(pk != NULL)
			{

				std::string getAutoIncRow = "SELECT MAX("+pk->getName()+") AS "+pk->fieldName()+" FROM "+pk->ownerName();
				pStmt = con->prepareStatement(getAutoIncRow);
				sql::ResultSet* res = pStmt->executeQuery();
				ResultWrapper resWrapper(res);
				if(resWrapper.next())
					pk->takeValue(&resWrapper);
				else
					sucessfull = false;

				delete pStmt;
				pStmt = NULL;

				return sucessfull;
			}
		else
		{
			if(stmt != NULL) delete stmt;
			if(pStmt != NULL) delete pStmt;
			return true;
			#ifdef _DEBUG
			std::cout << "Warning that table aint got a pk" << std::endl;
			#endif
		}
	}
	catch(sql::SQLException& e)
	{
		std::cout << "Query error "<< e.getSQLState() << std::endl;
		return false;
	}
	
	return false;


}
bool Database::runQuery(IQuery* query)
{
	if(this->connected)
	{
		try
		{
			std::string queryStr = query->buildQuery();
			ErrorLogger::logInfo("Running Query on Database: "+queryStr);
			sql::PreparedStatement *pstmt = con->prepareStatement(queryStr);
			sql::ResultSet *res = pstmt->executeQuery();
			ResultWrapper* resWrapper = new ResultWrapper(res); 
			query->setQueryResult(resWrapper);

			delete pstmt;
			return true;
		}
		catch(sql::SQLException& e)
		{
			std::string error = e.getSQLState();
			std::cout << "Query error "<<error << std::endl;

			throw sql::SQLException(e);
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
