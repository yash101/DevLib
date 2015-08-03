#include "main.h"
#include "src/tcp_server.h"

class srv : public dev::TcpServer
{
protected:
  void worker(dev::TcpServerConnection* connection)
  {
    connection->write("Hello!\n");
  }
};

int main(int argc, char** argv)
{
//  return dev::TcpServer().start(1235);
  srv().start(1234);
}
