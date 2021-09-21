#include "ScopedTransaction.h"

#include "../../../../ErrorLogger/Errors/ErrorLogger.h"
#include "NoBullshitQuery.h"

namespace DatabaseTables {

ScopedTransaction::ScopedTransaction(
    DatabaseTables::Database* db_con
) :
    m_db_con(db_con){

    ResultWrapper result_wrapper;
    DatabaseTables::NoBullshitQuery rollback_query("START TRANSACTION");
    if(!m_db_con->runQuery(
        &rollback_query, 
        result_wrapper
    )){
        ErrorLogger::logError("Failed to start transaction");
    }
    
}

ScopedTransaction::~ScopedTransaction(){
    Commit();
}

void ScopedTransaction::Commit() {

    ResultWrapper result_wrapper;
    DatabaseTables::NoBullshitQuery rollback_query("COMMIT");
    if(!m_db_con->runQuery(
        &rollback_query, 
        result_wrapper
    )){
        ErrorLogger::logError("Failed to commit transaction");
    }
}

void ScopedTransaction::Abort() {

    ResultWrapper result_wrapper;
    DatabaseTables::NoBullshitQuery rollback_query("ROLLBACK");
    if(!m_db_con->runQuery(
        &rollback_query, 
        result_wrapper
    )){
        ErrorLogger::logError("Failed to commit transaction");
    }
}
}

