#include "IQuery.h"
#include "../../exportMacros.h"

namespace DatabaseTables {

class DLLCORE_API NoBullshitQuery
    :
        public IQuery{

public:

    NoBullshitQuery(std::string query);
    virtual ~NoBullshitQuery();

    std::string&& AsJson();

public: // IQuery
	virtual std::string buildQuery();
	virtual void setQueryResult(std::shared_ptr<ResultWrapper> result);

private:
    std::string m_query;
    std::shared_ptr<ResultWrapper> m_result;
};

}