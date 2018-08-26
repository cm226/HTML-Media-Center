#pragma once
#include "../ResultWrapper.h"

class ResultBase{

    public:
        virtual bool ReadNext(std::shared_ptr<ResultWrapper> result) = 0;
};


template<typename T>
class ResultList
    : public ResultBase{

public:
    ResultList(std::string colName)
    : m_col_name(colName)
    {

    }

    ~ResultList(){

    }

    bool ReadNext(
        std::shared_ptr<ResultWrapper> result
    ) override {

        if constexpr (std::is_same<T, std::string>::value){
            m_values.push_back(result->getString(m_col_name.c_str()));
        }

        return true;
    }

private:
    
    std::vector<T> m_values;
    std::string m_col_name;

};


template <typename T>
class ResultGroup :
    public ResultBase{

public:
    ResultGroup(
        std::string col_name,
        std::vector<std::shared_ptr<ResultBase>> children
    ):
        m_col_name(col_name),
        m_children(children),
        m_have_value(false) {


    }
    virtual ~ResultGroup(){}

    virtual bool ReadNext(
        std::shared_ptr<ResultWrapper> result
    ) override {
    
        do{

            T value;
            if constexpr (std::is_same<T, std::string>::value){
                value = result->getString(m_col_name.c_str());
            }
            
            if(!m_have_value){
                m_value = value;
                m_have_value = true;
            }

            if(value != m_value){
                return false;
            }

            for(auto& child : m_children){
                child->ReadNext(result);
            }
        } while(result->next());
        return false;
    }


private:
    T m_value;
    bool m_have_value;
    std::string m_col_name;
    std::vector<std::shared_ptr<ResultBase>> m_children;
};