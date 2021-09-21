#pragma once
#include "../ResultWrapper.h"
#include "ResultBase.h"
#include "ResultList.h"
#include "ResultGroup.h"
#include "ResultRow.h"


template<typename T>
class Results{

public:
    Results(ResultWrapper& res_wrapper){

        while(res_wrapper.next()){
			auto result = Push();
			result->ReadNext(res_wrapper);
		}

    }

    std::shared_ptr<T> Push(
    ){
        auto p = std::make_shared<T>();   
        m_results.push_back(p);
        return p;
    }

    auto begin(){
        return m_results.begin();
    }

    auto end(){
        return m_results.end();
    }


private:
    std::vector<std::shared_ptr<T>> m_results;

};