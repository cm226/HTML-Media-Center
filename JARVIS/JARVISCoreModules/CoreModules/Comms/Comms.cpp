/*
 * Comms.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: craig
 */


#include "Comms.h"
#include "Transever/TCPTransever.h"
#include "JSON/JSONCURLRequest.h"
#include <boost/bind.hpp>




Comms::Comms(): transever(io_service,45001,connecionFactory)
{
}

Comms::~Comms() {
}

void Comms::startComms()
{
	this->commsThread = new boost::thread(boost::bind(&Comms::doComms, this));
}

void Comms::doComms()
{
	this->io_service.run();
}

void Comms::stopComms()
{
	this->io_service.stop();

	this->commsThread->join();
	delete this->commsThread;
}



CommsNS::IJSONRequest* Comms::createJSONRequest()
{
	CommsNS::CurlManager &manager = this->curlMan;

	return new CommsNS::JSONCURLRequest(manager);
}

bool Comms::downloadFile(std::string const& URL, std::string const& fileName)
{
	return this->curlMan.downloadItemToFile(URL,fileName);
}




