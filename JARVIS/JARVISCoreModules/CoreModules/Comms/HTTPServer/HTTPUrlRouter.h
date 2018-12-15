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
        HTTPUrlRouter();

        void MapURLRequest(std::string url, URLHandle handler);

        bool HasHandler(const std::string& url);
        void Route(
                const std::string& url, 
                boost::network::http::server<HTTPServer>::request request,
                boost::network::http::server<HTTPServer>::connection_ptr connection
        );

    private:
        std::map<std::string, URLHandle> m_handler_map;

        class Connection : 
            public IHTTPUrlRouter::IConnection
        {
            public:
                Connection();
                void Write(std::string);   

                std::string toString();
            private:
                std::stringstream msg;
        };

};