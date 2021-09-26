#pragma once

#include "IQuery.h"
#include "../../exportMacros.h"
#include "../Database.h"


namespace DatabaseTables {


class DLLCORE_API ScopedTransaction
{
public:

	ScopedTransaction(DatabaseTables::Database* db_con);
	virtual ~ScopedTransaction();

	void Abort();
    void Commit();




private:

    DatabaseTables::Database* m_db_con;

};
}
