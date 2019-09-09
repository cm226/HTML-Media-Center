/*
 * IPGetter.h
 *
 *  Created on: 6 Sep 2013
 *      Author: craig
 */

#ifndef IPGETTER_H_
#define IPGETTER_H_

#include <string>

namespace Comms {

class IPGetter {
public:
	IPGetter();
	virtual ~IPGetter();

	std::string getLANIP();
	std::string getWANIP();
};

} /* namespace Comms */
#endif /* IPGETTER_H_ */
