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


class Comms : public CommsNS::IComms{
private:
	boost::asio::io_service io_service;
	TranseverConnectionFactory connecionFactory;

	TCPAsyncTransever transever;
	CommsNS::CurlManager curlMan;

	boost::thread* commsThread;

	void doComms();

public:

	Comms();
	virtual ~Comms();

	void startComms();
	void stopComms();

	coremodules::comms::messagetranslaters::messagesubject::MessageSubject* messagesubject();
	static coremodules::comms::messagetranslaters::messagesubject::MessageSubject _messageSubject;

	CommsNS::IJSONRequest* createJSONRequest();
	bool downloadFile(std::string const& URL, std::string const& fileName);


};

#endif /* COMMS_H_ */
