/*
	Author : Craig Matear
*/
#pragma once
#ifndef COREMODULES_COMMS_MESSAGETRANSLATERS_MESSAGESUBJECT_MESSAGESUBJECTEVENT_H
#define COREMODULES_COMMS_MESSAGETRANSLATERS_MESSAGESUBJECT_MESSAGESUBJECTEVENT_H


#include "../../Protocals/IProtocal.h"
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include "../../../exportMacros.h"

namespace coremodules {
namespace comms {
namespace messagetranslaters {
namespace messagesubject {


template<typename Message>
class DLLCORE_API MessageSubjectEvent
{
private:
	#pragma warning( disable : 4251)
	boost::function<void (Message*, coremodules::comms::protocals::IProtocal*)> onListPluginsMessageReceved;
	#pragma warning( default : 4251)

public:
	MessageSubjectEvent(){};
	~MessageSubjectEvent(){};

	template<typename Listener>
	void connect(Listener* obj, void (Listener::*member)(Message*, coremodules::comms::protocals::IProtocal*))
	{
		onListPluginsMessageReceved = boost::bind(member,obj,_1,_2);
	}

	void signal(Message* m, coremodules::comms::protocals::IProtocal* p)
	{
		onListPluginsMessageReceved(m ,p);
	}

};




}
}
}
}


#endif



