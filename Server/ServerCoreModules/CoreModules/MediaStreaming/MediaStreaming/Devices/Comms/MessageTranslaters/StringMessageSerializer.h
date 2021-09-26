/*
	Author : Craig Matear
*/
#pragma once
#ifndef COREMODULES_COMMS_MESSAGETRANSLATERS_MESSAGESERIALIZER_H
#define COREMODULES_COMMS_MESSAGETRANSLATERS_MESSAGESERIALIZER_H
#include <string>
#include <sstream>

#include <iterator>

#define sepChar '$';

namespace coremodules {
namespace comms {
namespace messagetranslaters {


/**
	MessageSerializer
*/
class StringMessageSerializer
{
private:
	std::stringstream msg;
	
public:
	/**
		ctor
	*/
	StringMessageSerializer();

	/**
		dtor
	*/
	~StringMessageSerializer();

	template<typename T>
	void serialiseValue(T i)
	{
		this->msg << i << sepChar;
	};

	std::string serialize();

};




}
}
}


#endif



