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
                    "<div class=\"\widgit\">" +
                        widgit_str + 
                    "</div>");
            }
        }
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
        std::make_shared<TxtFileSource>(m_static_content + widgit, ".html")
    );
    file->SetLocation(Directory(m_static_content + widgit), "widgit.html");

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


