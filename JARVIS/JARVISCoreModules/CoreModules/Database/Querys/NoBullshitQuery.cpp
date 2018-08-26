#include "NoBullshitQuery.h"
#include "../../../../ErrorLogger/Errors/ErrorLogger.h"

#include <sstream>

namespace DatabaseTables{


NoBullshitQuery::NoBullshitQuery(
    std::string query
)
    :m_query(query),
    m_result(nullptr)
{


}

NoBullshitQuery::~NoBullshitQuery(
) {

}

std::string&& NoBullshitQuery::AsJson(
){
    if(m_result == nullptr){
        ErrorLogger::logError(
            "Access to NoBullshit query before results are in");
    }

    std::stringstream json;
    //auto col_names =  m_result->getColumnListMetaData();


    // while (m_result->next()){
        

    // }

    return "";
}

std::string NoBullshitQuery::buildQuery()
{
    return m_query;
}

void NoBullshitQuery::setQueryResult(
    std::shared_ptr<ResultWrapper> result
){
    m_result = result;
}

};