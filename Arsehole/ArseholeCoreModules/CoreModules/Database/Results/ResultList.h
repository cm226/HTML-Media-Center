
#pragma once
#include "ResultBase.h"
#include "Column.h"
#include "../../../../ErrorLogger/Errors/ErrorLogger.h"

template<typename ColumnT>
class ResultList
    : public ResultBase{

public:
    ResultList()
    {

    }

    ~ResultList(){

    }

    bool ReadNext(
       ResultWrapper& result
    ) override {

        ColumnT col;
        col.ReadNext(result);
        m_values.push_back(col);
        
        return true;
    }

    std::vector<ColumnT>& Values(){
        return m_values;
    }

private:
    
    std::vector<ColumnT> m_values;

};