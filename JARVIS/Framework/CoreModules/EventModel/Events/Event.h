/*
 * Event.h
 *
 *  Created on: Sep 28, 2012
 *      Author: craig
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <map>
#include "../EventHandler/EventHandler.h"

	typedef int CppEventHandler;

template <typename ReturnT, typename ParamT>
class Event {

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
	}

	bool detach(CppEventHandler id)
	{
		typename HandlersMap::iterator it = handlers.find(id);

		if(it == handlers.end())
			return false;

		delete it->second;
		handlers.erase(it);
		return true;
	}

	ReturnT notify(ParamT param)
	{
		typename HandlersMap::iterator it = handlers.begin();
		for(; it != handlers.end(); it++)
		{
			it->second->notify(param);
		}

		return true;
	}

};

#endif /* EVENT_H_ */
