#pragma once 

#include <string>
#include <map>
#include <functional>

#include <boost/network/protocol/http/server.hpp>

#include "IHTTPUrlRouter.h"

class HTTPServer;


class HTTPUrlRouter :
    public IHTTPUrlRouter 
{

    public:
        HTTPUrlRouter(std::string static_content);

        void MapURLRequest(std::string url, URLHandle handler);
        void RegisterWidgit(std::string widgit);

        bool HasHandler(const std::string& url);
        void Route(
                const std::string& url, 
                boost::network::http::server<HTTPServer>::request request,
                boost::network::http::server<HTTPServer>::connection_ptr connection
        );

    private:
        std::map<std::string, URLHandle> m_handler_map;
        std::vector<std::shared_ptr<File>> m_widgits;
        std::string m_static_content;

        class Connection : 
            public IHTTPUrlRouter::IConnection
        {
            public:
                Connection(std::string request_body);
                void Write(std::string);   

                std::string toString();

                std::string RequestBody();
                
            private:
                std::string m_request_body;
                std::stringstream msg;
        };

};