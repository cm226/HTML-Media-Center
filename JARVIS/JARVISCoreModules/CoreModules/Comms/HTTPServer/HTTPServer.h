#include <boost/network/protocol/http/server.hpp>
#include <iostream>

namespace http = boost::network::http;

class HTTPServer;
typedef std::function<
            void(
                http::server<HTTPServer>::request,
                http::server<HTTPServer>::connection_ptr
             )> URLHandle;

class HTTPServer {
    public:

        HTTPServer(std::string static_content);
        
        void operator()(
            http::server<HTTPServer>::request const &request,
            http::server<HTTPServer>::connection_ptr connection
        );
    

        void MapURLRequest(std::string url, URLHandle handler);
    private:
        std::string m_static_content;
        std::map<std::string, URLHandle> m_handler_map;
};