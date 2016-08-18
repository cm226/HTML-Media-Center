#ifndef UPDATE_QUERY_H
#define UPDATE_QUERY_H

#include "IQuery.h"
#include "../Tables/DatabaseTable.h"
#include "../../exportMacros.h"


namespace DatabaseTables {


class DLLCORE_API UpdateQuery : public IQuery
{
public:

	UpdateQuery(DatabaseTable* row);
	virtual ~UpdateQuery();

	std::string buildQuery();
	void setQueryResult(ResultWrapper* result);


private:
	DatabaseTable* row;
};
}

#endif