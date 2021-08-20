#pragma once

#include <iostream>
#include "HTTPUrlRouter.h"

class HTTPServer {
    public:

        HTTPServer(
            std::string static_content,
            std::shared_ptr<HTTPUrlRouter> router
        );
        
        void operator()(
            boost::network::http::server<HTTPServer>::request const &request,
            const boost::network::http::server<HTTPServer>::connection_ptr& connection
        );

        void HandleRequest(
            boost::network::http::server<HTTPServer>::request const &request,
            const boost::network::http::server<HTTPServer>::connection_ptr& connection
        );

    private:
        std::map<std::string, std::string> get_queries(
            const std::string dest,
            std::string& url_out
        );
    

        
    private:
        std::string m_static_content;
        std::shared_ptr<HTTPUrlRouter> m_router;
};