/*
 * IPGetter.cpp
 *
 *  Created on: 6 Sep 2013
 *      Author: craig
 */

#include "IPGetter.h"
#include "../../../ErrorLogger/Errors/ErrorLogger.h"

#ifdef _WIN32

#else
#include "GetLanIPLinux.h"
#endif

namespace Comms {

IPGetter::IPGetter()
{
}

IPGetter::~IPGetter()
{
}

std::string IPGetter::getLANIP()
{
#ifdef _WIN32
	//windows Code
	return "127.0.0.1";
#else
	// UNIX code
	GetLanIPLinux linxIPGetter;
	return linxIPGetter.getIP();
#endif
}
std::string IPGetter::getWANIP()
{
	return "127.0.0.1";
}

} /* namespace Comms */
