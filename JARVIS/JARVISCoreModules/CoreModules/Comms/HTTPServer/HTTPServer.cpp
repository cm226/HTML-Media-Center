#include "HTTPServer.h"

#include "../../Files/Files.h"

typedef http::server<HTTPServer> server;

HTTPServer::HTTPServer(
    std::string static_content
) {

    m_static_content = static_content;
}

void HTTPServer::operator()(
    server::request const &request,
    server::connection_ptr connection
) {
    server::string_type ip = source(request);
    std::string destination = request.destination;

    if(m_handler_map.find(destination) != m_handler_map.end()){
        m_handler_map[destination](request, connection);
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

void HTTPServer::MapURLRequest(
        std::string url,
        URLHandle handler) {

            void* that = this;
            auto pair = std::make_pair(url, handler);
            m_handler_map.emplace(pair);

}
