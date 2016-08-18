/*
	Author : Craig Matear
*/
#pragma once
#ifndef COREMODULES_EVENTMODEL_EVENTS_EVENTSIG_H
#define COREMODULES_EVENTMODEL_EVENTS_EVENTSIG_H

#include <vector>
#include<boost/bind.hpp>
#include<boost/signal.hpp>

#include "../../exportMacros.h"


namespace coremodules {
namespace eventmodel {
namespace events {

template<typename Container>
struct aggregate_values
{
  typedef Container result_type;

  template<typename InputIterator>
  Container operator()(InputIterator first, InputIterator last) const
  {
    return Container(first, last);
  }
};


/**
	EventSig
*/
template <typename ReturnT, typename ParamT>
class DLLCORE_API EventSig
{
private:
	#pragma warning( disable : 4251)
	boost::signal<ReturnT (ParamT),aggregate_values<std::vector<ReturnT> > > sig;
	#pragma warning( default: 4251)

public:
	EventSig(){};
	~EventSig(){};

	template <typename ListenerT>
	void attach(ListenerT* object,ReturnT (ListenerT::*member)(ParamT))
	{
		this->sig.connect(boost::bind(member,object, _1));
	};


	void notify(ParamT param, std::vector<ReturnT>* retVals = NULL)
	{
		*retVals = this->sig(param);
	};

};




}
}
}


#endif



