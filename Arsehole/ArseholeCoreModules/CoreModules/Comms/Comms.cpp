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

        auto err = BIO_new_fp(stderr, BIO_NOCLOSE);
        SSL_load_error_strings();

        OpenSSL_add_all_ciphers();

        // setup boost::asio::io_service
        m_io_service = std::make_shared<boost::asio::io_service>();
            
        // Initialize SSL context
        std::shared_ptr<boost::asio::ssl::context> ctx =    
            std::make_shared<boost::asio::ssl::context>(
                boost::asio::ssl::context::tlsv12);
        ctx->set_options(boost::asio::ssl::context::default_workarounds);

        SSL_CTX_set_ecdh_auto(ctx->native_handle(), 1);
        if(SSL_CTX_set_cipher_list(ctx->native_handle(), "ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-ECDSA-CHACHA20-POLY1305:ECDHE-RSA-CHACHA20-POLY1305:DHE-RSA-CHACHA20-POLY1305:ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-AES256-SHA384:DHE-RSA-AES256-SHA256:ECDHE-ECDSA-AES128-SHA256:ECDHE-RSA-AES128-SHA256:DHE-RSA-AES128-SHA256:RSA-PSK-CHACHA20-POLY1305:DHE-PSK-CHACHA20-POLY1305:ECDHE-PSK-CHACHA20-POLY1305:PSK-AES256-GCM-SHA384:PSK-CHACHA20-POLY1305") == 0){
            ERR_print_errors(err);
            ErrorLogger::logError("Failed to select cipher");
        }
        // Set keys
        ctx->set_password_callback(password_callback);
        ctx->use_certificate_chain_file("cert.pem");
        ctx->use_certificate_file("cert.pem", boost::asio::ssl::context::pem);
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

        // signal that the server is up now
        sig_server_running();

        // this call blocks
        m_server->run();

        m_io_service->stop();
    }
    catch (std::exception &e) {
        ErrorLogger::logError(std::string("Error while starting web server ") + e.what());
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



