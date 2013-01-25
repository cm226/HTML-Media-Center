/*
 * IComms.h
 *
 *  Created on: Jan 19, 2013
 *      Author: craig
 */

#ifndef ICOMMS_H_
#define ICOMMS_H_

#include "JSON/IJSONRequest.h"

namespace CommsNS {
	class IComms
	{
	public:
		IComms(){};
		virtual ~IComms(){};
		virtual IJSONRequest* createJSONRequest() = 0;
		virtual bool downloadFile(std::string const& URL, std::string const& fileName) = 0;

		virtual void stopComms() = 0;
		virtual void startComms() = 0;
	};
}






#endif /* ICOMMS_H_ */
