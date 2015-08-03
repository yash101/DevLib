#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H
#include "tcp_server.h"
namespace dev
{
  class HttpServer;
  class HttpServerRequest;

  class HttpServer : public dev::TcpServer
  {
  protected:
    void worker(dev::TcpServerConnection* connection);
  private:
  public:
  };

  class HttpServerRequest
  {
  public:
    dev::TcpServerConnection* _connection;
    std::string path;
    std::string unprocessed_path;
  };
}
#endif
