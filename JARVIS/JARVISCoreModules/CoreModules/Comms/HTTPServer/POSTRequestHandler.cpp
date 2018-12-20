#include "POSTRequestHandler.h"

#include "HTTPServer.h"

POSTRequestHandler::POSTRequestHandler(
    const boost::network::http::server<HTTPServer>::request& request)
      : content_length_(0),
        m_request(request) {
    
    for (const auto& header : request.headers) {
      std::cout << header.name << ": " << header.value << '\n';
      if (boost::iequals(header.name, "content-length")) {
        content_length_ = std::stoul(header.value);
      }
    }
  }

void POSTRequestHandler::operator()(boost::network::http::server<HTTPServer>::connection::input_range chunk,
                boost::system::error_code ec, size_t chunk_size,
                boost::network::http::server<HTTPServer>::connection_ptr connection,
                HTTPServer* server) {
    assert(chunk.size() == chunk_size);
    std::cout << "Chunk size: " << chunk_size << '\n';

    if (ec) {
        std::cerr << "Error code: " << ec << '\n';
        return;
    }

    body_.append(chunk.begin(), chunk.end());
    if (body_.size() < content_length_) {
        auto self = this->shared_from_this();
        connection->read([self, server](boost::network::http::server<HTTPServer>::connection::input_range chunk,
                                boost::system::error_code ec, size_t chunk_size,
                                boost::network::http::server<HTTPServer>::connection_ptr connection) {
        (*self)(chunk, ec, chunk_size, connection, server);
        });
        return;
    }
    
    m_request.body = body_;
    server->HandleRequest(m_request, connection);
}

