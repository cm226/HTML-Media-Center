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

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

#include <memory>



coremodules::comms::messagetranslaters::messagesubject::MessageSubject Comms::_messageSubject;

Comms::Comms()
{

}

Comms::~Comms() {
}

void Comms::startComms(std::string static_content)
{
    m_static_content_path = static_content;
    m_router = std::make_shared<HTTPUrlRouter>(m_static_content_path);

	this->serverThread = 
		std::make_unique<std::thread>(&Comms::doHTTP, this);
}

std::string password_callback(
    std::size_t max_length,
    boost::asio::ssl::context_base::password_purpose purpose) {
  return std::string("test");
}

void Comms::doHTTP()
{
	try {

        // setup boost::asio::io_service
        m_io_service = std::make_shared<boost::asio::io_service>();
            
        // Initialize SSL context
        std::shared_ptr<boost::asio::ssl::context> ctx =
            std::make_shared<boost::asio::ssl::context>(
                boost::asio::ssl::context::sslv23);
        ctx->set_options(boost::asio::ssl::context::default_workarounds |
                        boost::asio::ssl::context::no_sslv2 |
                        boost::asio::ssl::context::single_dh_use);

        // Set keys
        ctx->set_password_callback(password_callback);
        ctx->use_certificate_chain_file("cert.pem");
        ctx->use_private_key_file("key.pem", boost::asio::ssl::context::pem);

        HTTPServer handler(m_static_content_path, m_router);
        
        boost::network::http::server<HTTPServer>::options options(handler);
        m_server = std::make_shared<boost::network::http::server<HTTPServer>>(
            options.address(Config::GetInstance()->Host())
            .port("8442")
            .io_service(m_io_service)
            .reuse_address(true)
             .thread_pool(
                std::make_shared<boost::network::utils::thread_pool>(2))
            .context(ctx));

        // this call blocks
        m_server->run();

        m_io_service->stop();
    }
    catch (std::exception &e) {
        ErrorLogger::logError(std::string("Error while starting server") + e.what());
    }
}

void Comms::stopComms(){
    if(m_server != nullptr){
        m_server->stop();
        ErrorLogger::logInfo("Stopping server");

        this->serverThread->join();
    }
    
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

std::shared_ptr<IHTTPUrlRouter> Comms::Router(){

    if(m_router == nullptr){
        ErrorLogger::logError("Getting URL router before comms has started!!!");
    }
    return m_router;
}



