
#pragma once
#include "ResultBase.h"
#include "Column.h"

template<typename... TChildren>
class ResultRow
    : public ResultBase{

public:
    ResultRow()
    {
    }

    ~ResultRow(){

    }

    bool ReadNext(
       ResultWrapper& result
    ) override {

        ReadRow(m_columns, result);

        return false;
    }

    std::tuple<TChildren...>& Row(){
        return m_columns;
    }

private:

// some template functions for iterating children
template<std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), void>::type
  ReadRow(std::tuple<Tp...>& t, ResultWrapper& result)
  { }

template<std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I < sizeof...(Tp), void>::type
  ReadRow(std::tuple<Tp...>& t, ResultWrapper& result)
  {
    std::get<I>(t).ReadNext(result);
    ReadRow<I + 1, Tp...>(t, result);
  }


private:
    
    std::tuple<TChildren...> m_columns;

};