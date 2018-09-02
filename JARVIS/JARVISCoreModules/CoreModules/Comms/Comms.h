/*
 * Comms.h
 *
 *  Created on: Sep 26, 2012
 *      Author: craig
 */

#ifndef COMMS_H_
#define COMMS_H_

#include <string>
#include "../../../ErrorLogger/Errors/ErrorLogger.h"

#include "Transever/TCPAsyncTransever.h"
#include "Transever/TranseverConnectionFactory.h"

#include "IComms.h"
#include "CURL/CurlManager.h"
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>

#include <memory>

class HTTPServer;
class HTTPUrlRouter;

class Comms : public CommsNS::IComms{
private:
	TranseverConnectionFactory connecionFactory;

	CommsNS::CurlManager curlMan;

	std::unique_ptr<boost::thread> serverThread;
	std::string m_static_content_path;
	void doHTTP();

public:

	Comms();
	virtual ~Comms();

	void startComms(std::string static_content_path = "") override;
	void stopComms() override;
	
	std::shared_ptr<HTTPUrlRouter> Router() override;
	
	coremodules::comms::messagetranslaters::messagesubject::MessageSubject* messagesubject() override;
	static coremodules::comms::messagetranslaters::messagesubject::MessageSubject _messageSubject;

	CommsNS::IJSONRequest* createJSONRequest() override;
	bool downloadFile(std::string const& URL, std::string const& fileName) override;

private:

	std::shared_ptr<HTTPServer> m_server;
	std::shared_ptr<HTTPUrlRouter> m_router;

};

#endif /* COMMS_H_ */
