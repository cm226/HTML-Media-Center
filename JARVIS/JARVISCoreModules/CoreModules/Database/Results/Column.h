#pragma once
#include "ResultBase.h"
#include "../../../../ErrorLogger/Errors/ErrorLogger.h"

template<typename T, const char* col_name>
class Column
    : public ResultBase{

public:
    Column()
    : m_col_name(col_name)
    {
    }

    ~Column(){

    }

    bool ReadNext(
       ResultWrapper& result
    ) override {

        if constexpr (std::is_same<T, std::string>::value){
            m_value = result.getString(m_col_name.c_str());
            return true;
        }

        if constexpr (std::is_same<T, bool>::value){
            m_value = result.getBoolean(m_col_name.c_str());
            return true;
        }

        ErrorLogger::logError(std::string("invalid template type in column:  ") + __PRETTY_FUNCTION__);
        return true;
        
    }

    T Value(){
        return m_value;
    }

private:
    
    T m_value;
    std::string m_col_name;

};