/*
 * GetLanIPLinux.h
 *
 *  Created on: 6 Sep 2013
 *      Author: craig
 */

#ifndef GETLANIPLINUX_H_
#define GETLANIPLINUX_H_

#include <string>

namespace Comms {

class GetLanIPLinux {
public:
	GetLanIPLinux();
	virtual ~GetLanIPLinux();

	std::string getIP();
};

} /* namespace Comms */
#endif /* GETLANIPLINUX_H_ */
