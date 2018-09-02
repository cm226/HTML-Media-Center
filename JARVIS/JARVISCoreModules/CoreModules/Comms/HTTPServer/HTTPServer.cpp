#include "HTTPServer.h"

#include <boost/network/protocol/http/server.hpp>

#include "../../Files/Files.h"


typedef boost::network::http::server<HTTPServer> server;

HTTPServer::HTTPServer(
    std::string static_content,
    std::shared_ptr<HTTPUrlRouter> router
) {

    m_static_content = static_content;
    m_router = router;
}

void HTTPServer::operator()(
    server::request const &request,
    server::connection_ptr connection
) {
    server::string_type ip = source(request);
    std::string destination = request.destination;

    if(m_router->HasHandler(destination)){
        m_router->Route(
            destination,
            request,
            connection);
        return;
    }

    // we dont have a handler so check if its a static resource
    if(destination == "/"){
        destination = "index.html";
    }

    std::string requested_resource = 
        m_static_content + destination;

    TxtFileSource requested_file_source(requested_resource);
    std::string file_data;
    requested_file_source.GetData(file_data);


    connection->write(file_data);
}

