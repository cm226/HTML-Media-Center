#include "HTTPUrlRouter.h"

HTTPUrlRouter::Connection::Connection(
    std::string request_body){

        m_request_body = request_body;
}

std::string HTTPUrlRouter::Connection::RequestBody(
){
    return m_request_body;
}

void HTTPUrlRouter::Connection::Write(
    std::string text
) {
    msg << text;
}

std::string HTTPUrlRouter::Connection::toString(){
    return msg.str();
}

HTTPUrlRouter::HTTPUrlRouter(    
){

}

void HTTPUrlRouter::MapURLRequest(
    std::string url,
    URLHandle handler
) {
    auto pair = std::make_pair(url, handler);
    m_handler_map.emplace(pair);

}

bool HTTPUrlRouter::HasHandler(
    const std::string& url
){
    return m_handler_map.find(url) != m_handler_map.end();
}

void HTTPUrlRouter::Route(
    const std::string& url, 
    boost::network::http::server<HTTPServer>::request request,
    boost::network::http::server<HTTPServer>::connection_ptr connection_ptr
) {
    auto handler = m_handler_map[url];
    auto connection = std::make_shared<Connection>(request.body);
    handler(connection);

    connection_ptr->set_status(boost::network::http::server<HTTPServer>::connection::ok);
    std::map<std::string, std::string> headers;
    connection_ptr->set_headers(headers);

    connection_ptr->write(connection->toString());
    
}


