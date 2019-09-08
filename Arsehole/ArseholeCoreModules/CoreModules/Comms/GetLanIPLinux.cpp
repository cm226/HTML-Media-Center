/*
 * GetLanIPLinux.cpp
 *
 *  Created on: 6 Sep 2013
 *      Author: craig
 */

#include "GetLanIPLinux.h"
#include "../../../ErrorLogger/Errors/ErrorLogger.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>

namespace Comms {

GetLanIPLinux::GetLanIPLinux()
{
}

GetLanIPLinux::~GetLanIPLinux()
{
}

std::string GetLanIPLinux::getIP()
{
	struct ifaddrs *ifaddr, *ifa;
	int family, s;
	char host[NI_MAXHOST];

	if (getifaddrs(&ifaddr) == -1)
		ErrorLogger::logError("Failed to get network inteface card LAN IP :( ");

	for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
	   if (ifa->ifa_addr == NULL)
		   continue;

	   family = ifa->ifa_addr->sa_family;

	   if (family == AF_INET || family == AF_INET6)
	   {
		   std::string name = ifa->ifa_name;
		   if(name.find("wlan",0) != std::string::npos &&
				   name.find("wlan",0) != std::string::npos)
		   {

			   s = getnameinfo(ifa->ifa_addr,
					   (family == AF_INET) ? sizeof(struct sockaddr_in) :
											 sizeof(struct sockaddr_in6),
					   host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
			   ErrorLogger::logInfo("host: "+std::string(host));
			   return std::string(host);
			   if (s != 0)
				   ErrorLogger::logError("getnameinfo failed");
		   }
	   }
	}

	freeifaddrs(ifaddr);
	return "";
}

} /* namespace Comms */
