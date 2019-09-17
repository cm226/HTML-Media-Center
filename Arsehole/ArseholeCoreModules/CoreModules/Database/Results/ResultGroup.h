
#pragma once
#include "ResultBase.h"

template <
    typename Type,
    const char* col_name,
    typename... TChildren>
class ResultGroup :
    public ResultBase{

public:
    ResultGroup(
    ):
        m_col_name(col_name),
        m_have_value(false) {
    }
    virtual ~ResultGroup(){}

    virtual bool ReadNext(
        ResultWrapper& result
    ) override {
    
        do{

            Type value;
            if constexpr (std::is_same<Type, std::string>::value){
                value = result.getString(m_col_name.c_str());
            }

            if constexpr (std::is_same<Type, bool>::value){
                value = result.getBoolean(m_col_name.c_str());
            }

            
            
            if(!m_have_value){
                m_value = value;
                m_have_value = true;
            }

            // If we encounter a value in the results list
            // That dosnt belong to this group then return 
            // because we have reached the end of this group.
            if(value != m_value){
                // since we have not used this group, we 
                // wind back the results wrapper
                result.unNext();
                return false;
            }

            ReadChild(m_children, result);
        } while(result.next());
        return false;
    }



public: 
    Type Value(){
        return m_value;
    }

    std::tuple<TChildren...>& Children(){
        return m_children;
    }

private:

// some template functions for iterating children
template<std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), void>::type
  ReadChild(std::tuple<Tp...>& t, ResultWrapper& result)
  { }

template<std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I < sizeof...(Tp), void>::type
  ReadChild(std::tuple<Tp...>& t, ResultWrapper& result)
  {
    std::get<I>(t).ReadNext(result);
    ReadChild<I + 1, Tp...>(t, result);
  }


private:
    Type m_value;
    bool m_have_value;
    std::string m_col_name;
    std::tuple<TChildren...> m_children;
};