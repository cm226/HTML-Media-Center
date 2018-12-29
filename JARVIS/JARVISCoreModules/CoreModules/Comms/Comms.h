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
#include <boost/asio.hpp>
#include <boost/network/protocol/http/server.hpp>

#include <memory>

class HTTPServer;
class IHTTPUrlRouter;
class HTTPUrlRouter;


class Comms : public CommsNS::IComms{
private:
	TranseverConnectionFactory connecionFactory;

	CommsNS::CurlManager curlMan;

	std::unique_ptr<std::thread> serverThread;
	std::string m_static_content_path;
	void doHTTP();

public:

	Comms();
	virtual ~Comms();

	void startComms(std::string static_content_path = "") override;
	void stopComms() override;
	
	std::shared_ptr<IHTTPUrlRouter> Router() override;
	
	coremodules::comms::messagetranslaters::messagesubject::MessageSubject* messagesubject() override;
	static coremodules::comms::messagetranslaters::messagesubject::MessageSubject _messageSubject;

	CommsNS::IJSONRequest* createJSONRequest() override;
	bool downloadFile(std::string const& URL, std::string const& fileName) override;

private:

	std::shared_ptr<HTTPUrlRouter> m_router;

	std::shared_ptr<boost::network::http::server<HTTPServer>> m_server;
	std::shared_ptr<boost::asio::io_service> m_io_service;

};

#endif /* COMMS_H_ */
