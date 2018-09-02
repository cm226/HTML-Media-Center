#include "HTTPUrlRouter.h"

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
    boost::network::http::server<HTTPServer>::connection_ptr connection
) {
    m_handler_map[url](request, connection);

}


