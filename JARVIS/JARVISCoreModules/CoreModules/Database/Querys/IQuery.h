#ifndef _IQUERY_H
#define _IQUERY_H

#include <string>
#include "../ResultWrapper.h"

namespace DatabaseTables {

class IQuery
{
public:
	virtual std::string buildQuery() = 0;
	virtual void setQueryResult(ResultWrapper* result) = 0;

private:

};
}
#endif
