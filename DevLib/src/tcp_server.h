#ifndef TCP_SERVER_H
#define TCP_SERVER_H
#include <string>
namespace dev
{
  class TcpServer;
  class TcpServerConnection;

  class TcpServer
  {
  protected:
    int _fd;
    void* _address;
    short int _port;
    bool _started;

    void accepter();
    void connector(TcpServerConnection* connection);
    virtual void worker(TcpServerConnection* connection);
  public:
    TcpServer();
    ~TcpServer();

    int start(int port);
  private:
  };

  class TcpServerConnection
  {
  protected:
  public:
    int _fd;
    void* _address;
    TcpServer* server;

    TcpServerConnection();
    ~TcpServerConnection();

    int read(char* buffer, size_t len);
    int read(char& byte);
    char read();

    int write(char byte);
    int write(char* data, size_t len);
    int write(std::string str);

    std::string readline(char end, size_t maxlen);
    bool readline(char* buffer, char end, size_t bufsize);
  };
}
#endif
