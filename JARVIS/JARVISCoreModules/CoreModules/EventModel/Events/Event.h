/*
 * Event.h
 *
 *  Created on: Sep 28, 2012
 *      Author: craig
 */

#ifndef EVENT_H_
#define EVENT_H_
#pragma warning( disable : 4251)

#include <map>
#include <vector>
#include <cstddef>
#include "../EventHandler/EventHandler.h"
#include "../../exportMacros.h"

typedef int CppEventHandler;

template <typename ReturnT, typename ParamT>
class DLLCORE_API Event {

	typedef std::map<int,EvntHandlerBase<ReturnT,ParamT>* > HandlersMap;
	HandlersMap handlers;
	int m_count;

public:
	Event(){m_count = 0;}

	template <typename ListenerT>
	CppEventHandler attach(ListenerT* object,ReturnT (ListenerT::*member)(ParamT))
	{
		typedef ReturnT (ListenerT::*PtrMember)(ParamT);
		handlers[m_count] = (new EventHandler<ListenerT,
								ReturnT,ParamT>(object,member));
		m_count++;
		return m_count-1;
	};

	bool detach(CppEventHandler id)
	{
		typename HandlersMap::iterator it = handlers.find(id);

		if(it == handlers.end())
			return false;

		delete it->second;
		handlers.erase(it);
		return true;
	};

	void notify(ParamT param, std::vector<ReturnT>* retVals = NULL)
	{
		typename HandlersMap::iterator it = handlers.begin();
		bool generateReturn = retVals != NULL;
		for(; it != handlers.end(); it++)
		{
			if(generateReturn)
				retVals->push_back(it->second->notify(param));
			else
				it->second->notify(param);
		}

		return;
	};

};

#endif /* EVENT_H_ */
#pragma warning( default : 4251)
