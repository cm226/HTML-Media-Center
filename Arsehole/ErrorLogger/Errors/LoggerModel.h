#pragma once

#include "ErrorLogger.h"

template<class T>
class LoggerModel{

public:
    LoggerModel(
        std::string msg,
        T init
    ) :
        m_msg(msg),
        m_value(init) {

    }

    virtual ~LoggerModel(){};

public:

    void Set(T value){
        if(value != m_value){
            ErrorLogger::logInfo(m_msg + ":" +std::to_string(value));
            m_value = value;
        }
    }

    T Get(){
        return m_value;
    }

private:

    std::string m_msg;
    T m_value;

};