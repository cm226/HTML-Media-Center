
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
            boost::network::http::server<HTTPServer>::connection_ptr connection
        );
    

        
    private:
        std::string m_static_content;
        std::shared_ptr<HTTPUrlRouter> m_router;
};