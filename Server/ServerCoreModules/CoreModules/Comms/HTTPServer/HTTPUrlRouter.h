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
        void UnMapURLRequest(std::string url, URLHandle handler);
        
        void RegisterWidgit(std::string widgit);
        void RegisterPluginPage(std::string name, std::string url);

        bool HasHandler(const std::string& url);
        void Route(
                const std::string& url, 
                boost::network::http::server<HTTPServer>::request request,
                boost::network::http::server<HTTPServer>::connection_ptr connection,
                std::map<std::string, std::string> query_params
        );

    private:
        std::map<std::string, URLHandle> m_handler_map;
        std::map<std::string, std::shared_ptr<File>> m_widgits;
        std::map<std::string, std::string> m_plugins;
        std::string m_static_content;

        class Connection : 
            public IHTTPUrlRouter::IConnection
        {
            public:
                Connection(
                    std::string request_body,
                    std::map<std::string, std::string> query_params
                );

                void Write(std::string) override;   

                std::string toString();

                std::string RequestBody() override;

                std::map<std::string, std::string> RequestParams() override;
                
            private:
                std::map<std::string, std::string> m_query_params;
                std::string m_request_body;
                std::stringstream msg;
        };

};