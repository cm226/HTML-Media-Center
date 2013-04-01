#include "UpdateQuery.h"
#include <vector>
#include <sstream>

#include <exception>

namespace DatabaseTables {

UpdateQuery::UpdateQuery(DatabaseTable* row) : row(row)
{

}
UpdateQuery::~UpdateQuery()
{

}



std::string UpdateQuery::buildQuery()
{
	std::vector<IDatabaseTableField*> fields;
	std::vector<IDatabaseTableField*>::iterator fieldsIt;

	IDatabaseTableField* pk = this->row->getPrimaryKey();

	if(pk == NULL)
		throw std::runtime_error("No primary key on update table");

	this->row->getFields(&fields);
	std::stringstream query;
	query << "UPDATE " << this->row->tableName() << " SET ";
	bool writecomma = false;
	for(fieldsIt = fields.begin(); fieldsIt != fields.end(); fieldsIt++)
	{

		if((*fieldsIt) == pk)
			continue;

		if(writecomma)
			query << ',';

		writecomma = true;
		query << (*fieldsIt)->getName() << " = '" << (*fieldsIt)->getStrValue() <<"' ";
	}

	query << " WHERE " << pk->getName() << "=" <<pk->getStrValue();

	return query.str();
}
void UpdateQuery::setQueryResult(ResultWrapper* result)
{
	// no result for update
}

}