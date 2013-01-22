/*
 * EventHandler.h
 *
 *  Created on: Sep 28, 2012
 *      Author: craig
 */

#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_
#include "EvntHandlerBase.h"


template <typename ListenerT, typename ReturnT, typename ParamT>
class EventHandler : public EvntHandlerBase<ReturnT,ParamT>{

	typedef ReturnT (ListenerT::*PtrMember)(ParamT);

	ListenerT* m_object;
	PtrMember m_member;

public:

	EventHandler(ListenerT* object, PtrMember member) :
		m_object(object), m_member(member)
	{}
	virtual ~EventHandler(){};

	ReturnT notify(ParamT param)
	{
		return (m_object->*m_member)(param);
	}
};

#endif /* EVENTHANDLER_H_ */
