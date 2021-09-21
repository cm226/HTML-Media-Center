#ifndef _IQUERY_H
#define _IQUERY_H

#include <string>
#include "../ResultWrapper.h"

#include <memory>

namespace DatabaseTables {

class IQuery
{
public:
	virtual std::string buildQuery() = 0;

private:

};
}
#endif
