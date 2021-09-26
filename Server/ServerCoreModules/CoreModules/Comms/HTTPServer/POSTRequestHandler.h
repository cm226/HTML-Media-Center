#pragma once
#include <memory>

#include <boost/network/protocol/http/server.hpp>

class HTTPServer;

class POSTRequestHandler
    : public std::enable_shared_from_this<POSTRequestHandler> 
{
  public:

    explicit POSTRequestHandler(const boost::network::http::server<HTTPServer>::request& request);

    void operator()(boost::network::http::server<HTTPServer>::connection::input_range chunk,
                  boost::system::error_code ec, size_t chunk_size,
                  boost::network::http::server<HTTPServer>::connection_ptr connection,
                  HTTPServer* server
                  );

    std::string GetBody();
 private:
  size_t content_length_;
  std::string body_;

  const boost::network::http::server<HTTPServer>::request& m_request; // nothing dodgy going on here......
};