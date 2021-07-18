#include "HTTPServer.h"

#include <boost/network/protocol/http/server.hpp>

#include "POSTRequestHandler.h"

#include "../../Files/Files.h"
#include "../../../../ErrorLogger/Errors/ErrorLogger.h"

#include <boost/filesystem.hpp>


typedef boost::network::http::server<HTTPServer> server;

HTTPServer::HTTPServer(
    std::string static_content,
    std::shared_ptr<HTTPUrlRouter> router
) {

    m_static_content = static_content;
    m_router = router;
}

std::map<std::string, std::string> HTTPServer::get_queries(
    const std::string dest,
    std::string& url_out
) {

    std::size_t pos = dest.find_first_of("?");
    url_out = dest.substr(0, pos);

    std::map<std::string, std::string> queries;
    if (pos != std::string::npos) {
        std::string query_string = dest.substr(pos + 1);

        // Replace '&' with space
        for (pos = 0; pos < query_string.size(); pos++) {
            if (query_string[pos] == '&') {
                query_string[pos] = ' ';
            }
        }

        std::istringstream sin(query_string);
        while (sin >> query_string) {

            pos = query_string.find_first_of("=");

            if (pos != std::string::npos) {
                const std::string key = query_string.substr(0, pos);
                const std::string value = query_string.substr(pos + 1);
                queries[key] = value;
            }
        }
    }

    return queries;
}

void HTTPServer::HandleRequest(
    server::request const &request,
    const server::connection_ptr& connection
) {
    server::string_type ip = source(request);
    std::string destination = request.destination;
    std::string path;
    auto querys = get_queries(destination, path);

    if(m_router->HasHandler(path)){
        // crappy plugin may except when handling 
        // this request, catch and log error
        try{
            m_router->Route(
                path,
                request,
                connection,
                querys);
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
        destination = "/app/build/index.html";
    }

    // while switching to react this is temp
    if(destination == "/app/build/Shopping.html" ||
    destination == "/app/build/config.html" ||
    destination == "/app/build/Invest.html"){
        destination = "/app/build/index.html";
    }

    std::string requested_resource = 
        m_static_content + destination;

    // small hack while transitioning to React app
    if(!boost::filesystem::exists(requested_resource)){
        requested_resource = m_static_content + "/app/build/" + destination;
    }

    TxtFileSource requested_file_source(requested_resource, "html");
    std::string file_data;
    std::map<std::string, std::string> headers;



    if(!requested_file_source.GetData(file_data)){

        connection->set_status(server::connection::not_found);
        headers= { {"Content-Type", "text/html"}, {"Access-Control-Allow-Headers", "*"}};


        connection->set_headers(headers);
        connection->write("Im very sorry my good Man/Lady/other but i could not find that thing");
    } else {
        
        std::string ext = requested_file_source.ext();
        if(ext.compare(".css") == 0) {
            headers= { {"Content-Type", "text/css"}, };
        } else if(ext.compare(".js") == 0) {
            headers= { {"Content-Type", "application/javascript"}, };
        } else if(ext.compare(".ico") == 0){
            headers= { {"Content-Type", "image/x-icon"}, };
        }else {
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

