#include <boost/network/protocol/http/server.hpp>
#include <iostream>

namespace http = boost::network::http;

class HTTPServer;

class HTTPServer {
    public:

        HTTPServer(std::string static_content);
        
        void operator()(
            http::server<HTTPServer>::request const &request,
            http::server<HTTPServer>::connection_ptr connection
        );
    
    private:
        std::string m_static_content;
};