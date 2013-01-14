/*
 * Query.cpp
 *
 *  Created on: Nov 24, 2012
 *      Author: craig
 */

#include "Query.h"

#include <hash_set>
#include <exception>
#include <vector>

namespace DatabaseTables {

Query::Query() {
	this->result = NULL;
	this->fields = new std::vector<IDatabaseTableField*>();
	this->constraints = new std::vector<IConstraint*>();
}

Query::~Query() {
	delete this->result;
	delete this->fields;
	delete this->constraints;

}

void Query::addConstraint(IConstraint* con)
{
	this->constraints->push_back(con);
}

void Query::addSelectItem(IDatabaseTableField* field)
{
	this->fields->push_back(field);
}
void Query::addSelectItem(DatabaseTable* table)
{
	std::vector<IDatabaseTableField*> tableFields;
	std::vector<IDatabaseTableField*>::iterator fieldIt;

	table->getFields(&tableFields);

	
	for(fieldIt = tableFields.begin(); fieldIt != tableFields.end(); fieldIt++)
		this->fields->push_back((*fieldIt));

}

std::string Query::buildQuery()
{
	if(this->fields->size() == 0)
		throw std::exception("building query with no selected fields is stupid!");

	std::string selectString = "SELECT DISTINCT ";
	std::string whereString =  "";
	std::string fromString = " FROM";

	std::vector<IDatabaseTableField*>::iterator fieildIt;
	std::vector<IConstraint*>::iterator constraintIter;

	std::hash_set<std::string> tables;
	std::hash_set<std::string>::iterator tablesIt;



	for (fieildIt = this->fields->begin(); fieildIt != this->fields->end(); fieildIt++)
	{
		if(fieildIt != this->fields->begin()) selectString+= ", ";

			std::string name = (*fieildIt)->getName();
			selectString += name; // SELECT
			tables.insert((*fieildIt)->ownerName());
	}

	if(this->constraints->size() > 0)
	{
		whereString += " WHERE";
		for (constraintIter = this->constraints->begin(); constraintIter != this->constraints->end(); constraintIter++)
		{
			if(constraintIter != this->constraints->begin())
				whereString += " AND";

			whereString += " "+(*constraintIter)->getQuerystring();//WHERE

			std::vector<std::string> tableNames;
			std::vector<std::string>::iterator tnameIt;
			(*constraintIter)->getTableNames(&tableNames);
			for(tnameIt = tableNames.begin(); tnameIt != tableNames.end(); tnameIt++) tables.insert((*tnameIt));
		}
	}

	for (tablesIt = tables.begin(); tablesIt != tables.end(); tablesIt++)
	{
		if(tablesIt != tables.begin())
			fromString += " ,";

		fromString += " "+(*tablesIt);
	}//FROM
	
	
	
	return selectString+fromString+whereString;
}

void Query::listSelectedFields(IDatabaseTableField** fields, int* numOfFeilds)
{
	std::vector<IDatabaseTableField*>::iterator fieildIt;
	fields = new IDatabaseTableField*[this->fields->size()];
	int counter = 0;
	for (fieildIt = this->fields->begin(); fieildIt < this->fields->end(); fieildIt++)
	{
		fields[counter] = *fieildIt;
		counter++;
	}
	*numOfFeilds = counter+1;
}

void Query::setQueryResult(ResultWrapper* result)
{
	if(this->result != NULL)
		delete this->result;

	this->result = result;
}

bool Query::nextLine()
{
	if (this->result->next())
	{
		std::vector<IDatabaseTableField*>::iterator fieildIt;
		for (fieildIt = this->fields->begin(); fieildIt < this->fields->end(); fieildIt++)
		{
			(*fieildIt)->takeValue(this->result);

		}
		return true;
	}
	return false;
}

} /* namespace DatabaseTables */

