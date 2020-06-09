#include "HTTPUrlRouter.h"
#include "../../config.h"

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

HTTPUrlRouter::Connection::Connection(
    std::string request_body,
    std::map<std::string, std::string> query_params
){

        m_request_body = request_body;
        m_query_params = query_params;
}

std::string HTTPUrlRouter::Connection::RequestBody(
){
    return m_request_body;
}

std::map<std::string, std::string> HTTPUrlRouter::Connection::RequestParams(
) {
    return m_query_params;
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
    std::string static_content   
){
    m_static_content = static_content;

    MapURLRequest("/pluginWigits",[&](
		std::shared_ptr<IHTTPUrlRouter::IConnection> connection 
    ){
        for(auto widgit : m_widgits){
            std::string widgit_str;
            if(widgit->ToString(widgit_str)){
                connection->Write(
                    "<div class=\"widgit\">" +
                        widgit_str + 
                    "</div>");
            }
        }
    });


    MapURLRequest("/getVersion",[&](
		std::shared_ptr<IHTTPUrlRouter::IConnection> connection 
    ){
        connection->Write(Config::GetInstance()->Version());
    });

    MapURLRequest("/serverTime",[&](
		std::shared_ptr<IHTTPUrlRouter::IConnection> connection 
    ){
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);

        std::ostringstream oss;

        oss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%SZ");

        connection->Write(oss.str());

    });

    
}

void HTTPUrlRouter::MapURLRequest(
    std::string url,
    URLHandle handler
) {
    auto pair = std::make_pair(url, handler);
    m_handler_map.emplace(pair);

}

void HTTPUrlRouter::RegisterWidgit(
    std::string widgit
){
    auto file = std::make_shared<File>(
        std::make_shared<TxtFileSource>(Directory(m_static_content + widgit), "widgit","html")
    );

    m_widgits.push_back(file);
}

bool HTTPUrlRouter::HasHandler(
    const std::string& url
){
    return m_handler_map.find(url) != m_handler_map.end();
}

void HTTPUrlRouter::Route(
    const std::string& url, 
    boost::network::http::server<HTTPServer>::request request,
    boost::network::http::server<HTTPServer>::connection_ptr connection_ptr,
    std::map<std::string, std::string> query_params
) {
    auto handler = m_handler_map[url];
    auto connection = std::make_shared<Connection>(request.body, query_params);
    handler(connection);

    connection_ptr->set_status(boost::network::http::server<HTTPServer>::connection::ok);
    std::map<std::string, std::string> headers;
    connection_ptr->set_headers(headers);

    connection_ptr->write(connection->toString());
    
}


