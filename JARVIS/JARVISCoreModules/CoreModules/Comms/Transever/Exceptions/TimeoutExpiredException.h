/*
	Author : Craig Matear
*/
#pragma once
#ifndef COREMODULES_COMMS_TRANSEVER_EXCEPTIONS_TIMEOUTEXPIREDEXCEPTION_H
#define COREMODULES_COMMS_TRANSEVER_EXCEPTIONS_TIMEOUTEXPIREDEXCEPTION_H

#include <exception>
#include <stdexcept>

namespace coremodules {
namespace comms {
namespace transever {
namespace exceptions {


/**
	TimeoutExpiredException
*/
class TimeoutExpiredException : std::runtime_error
{
public:
	/**
		ctor
	*/
	explicit TimeoutExpiredException(const std::string& error_message);

	/**
		dtor
	*/
	virtual ~TimeoutExpiredException() throw();

};




}
}
}
}


#endif



