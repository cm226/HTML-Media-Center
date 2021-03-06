/*
 * IComms.h
 *
 *  Created on: Jan 19, 2013
 *      Author: craig
 */

#ifndef ICOMMS_H_
#define ICOMMS_H_

#include "JSON/IJSONRequest.h"
#include "MessageTranslaters/MessageSubject/MessageSubject.h"

#include <boost/signals2.hpp>

class IHTTPUrlRouter;

namespace CommsNS {
	class __attribute__((__visibility__("default"))) IComms
	{

	public:
		IComms(){};
		virtual ~IComms(){};
		virtual coremodules::comms::messagetranslaters::messagesubject::MessageSubject* messagesubject() =0 ;

		virtual IJSONRequest* createJSONRequest() = 0;
		virtual bool downloadFile(std::string const& URL, std::string const& fileName) = 0;

		virtual void stopComms() = 0;
		virtual void startComms(std::string static_content_path = "") = 0;
		virtual std::shared_ptr<IHTTPUrlRouter> Router() = 0;

	public:  //events

		boost::signals2::signal<void ()> sig_shutdown;
		boost::signals2::signal<void ()> sig_server_running;

	};
}






#endif /* ICOMMS_H_ */
