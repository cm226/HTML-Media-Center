/*
 * IPGetter.cpp
 *
 *  Created on: 6 Sep 2013
 *      Author: craig
 */

#include "IPGetter.h"


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
#elif linux
	// UNIX code
#include "GetLanIPLinux.h"
	GetLanIPLinux linxIPGetter;
	return linxIPGetter.GetLanIPLinux();
#endif


}
std::string IPGetter::getWANIP()
{
	return "127.0.0.1";
}

} /* namespace Comms */
