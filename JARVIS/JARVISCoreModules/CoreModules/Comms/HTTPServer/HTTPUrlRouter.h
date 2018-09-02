#pragma once 

#include <string>
#include <map>
#include <functional>

#include <boost/network/protocol/http/server.hpp>

class HTTPServer;
typedef std::function<
            void(
                boost::network::http::server<HTTPServer>::request,
                boost::network::http::server<HTTPServer>::connection_ptr
             )> URLHandle;


class HTTPUrlRouter{

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

};