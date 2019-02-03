#include "HTTPServer.h"

#include <boost/network/protocol/http/server.hpp>

#include "POSTRequestHandler.h"

#include "../../Files/Files.h"
#include "../../../../ErrorLogger/Errors/ErrorLogger.h"


typedef boost::network::http::server<HTTPServer> server;

HTTPServer::HTTPServer(
    std::string static_content,
    std::shared_ptr<HTTPUrlRouter> router
) {

    m_static_content = static_content;
    m_router = router;
}

void HTTPServer::HandleRequest(
    server::request const &request,
    const server::connection_ptr& connection
) {
    server::string_type ip = source(request);
    std::string destination = request.destination;

    if(m_router->HasHandler(destination)){
        // crappy plugin may except when handling 
        // this request, catch and log error
        try{
            m_router->Route(
                destination,
                request,
                connection);
            return;
        } catch (std::exception& e){
            ErrorLogger::logError(
                "exception while handling request : "
                 + destination + 
                 " exception was: " + e.what()
            );
        }
    }

    // we dont have a handler so check if its a static resource
    if(destination == "/"){
        destination = "index.html";
    }

    std::string requested_resource = 
        m_static_content + destination;



    TxtFileSource requested_file_source(requested_resource, "html");
    std::string file_data;
    std::map<std::string, std::string> headers;


    if(!requested_file_source.GetData(file_data)){

        connection->set_status(server::connection::not_found);
        headers= { {"Content-Type", "text/html"}, };


        connection->set_headers(headers);
        connection->write("Sorry bro couldent find that resource ");
    } else {
        
        std::string ext = requested_file_source.ext();
        if(ext.compare(".css") == 0) {
            headers= { {"Content-Type", "text/css"}, };
        } else if(ext.compare(".js") == 0) {
            headers= { {"Content-Type", "application/javascript"}, };
        } else {
            headers= { {"Content-Type", "text/html"}, };
        }
        connection->set_status(server::connection::ok);
        connection->set_headers(headers);
        connection->write(file_data);
        
    }

}

void HTTPServer::operator()(
    server::request const &request,
    const server::connection_ptr& connection
) {    

    // need to do a special thing for post to read the post data. 
    std::string body = request.body;
    if (request.method == "POST") {
      auto h = std::make_shared<POSTRequestHandler>(request);
      connection->read([h, this](server::connection::input_range chunk,
                           boost::system::error_code ec, size_t chunk_size,
                           server::connection_ptr connection) {
        (*h)(chunk, ec, chunk_size, connection, this);
      });
    } else{
        // GET 
        HandleRequest(request, connection);
    }

    
    
    
}

