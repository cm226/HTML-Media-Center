/*
 * Comms.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: craig
 */


#include "Comms.h"
#include "JSON/JSONCURLRequest.h"
#include "HTTPServer/HTTPServer.h"
#include "HTTPServer/HTTPUrlRouter.h"
#include <boost/bind.hpp>



coremodules::comms::messagetranslaters::messagesubject::MessageSubject Comms::_messageSubject;

Comms::Comms()
{

}

Comms::~Comms() {
}

void Comms::startComms(std::string static_content)
{
    m_static_content_path = static_content;
    m_router = std::make_shared<HTTPUrlRouter>();

	this->serverThread = 
		std::make_unique<boost::thread>(
			boost::bind(&Comms::doHTTP, this));
}

void Comms::doHTTP()
{
	try {
        HTTPServer handler(m_static_content_path, m_router);
        m_server = std::shared_ptr<HTTPServer>(&handler, [](auto p){});
        boost::network::http::server<HTTPServer>::options options(handler);
        boost::network::http::server<HTTPServer> server_(options.address(MY_HOST).port("8080"));
        server_.run();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Comms::stopComms(){

}


coremodules::comms::messagetranslaters::messagesubject::MessageSubject* Comms::messagesubject()
{
	return &_messageSubject;
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

std::shared_ptr<HTTPUrlRouter> Comms::Router(){

    if(m_router == nullptr){
        ErrorLogger::logError("Getting URL router before comms has started!!!");
    }
    return m_router;
}



