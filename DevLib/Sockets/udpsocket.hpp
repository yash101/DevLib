#ifndef UDPSOCKET_HPP
#define UDPSOCKET_HPP
#include <sys/socket.h>
#include <mutex>

namespace dev
{
    class UdpSocketServerConnection
    {
        int connid;
        int c;

        UdpSocketServerConnection() {}

        void put(char byte);
        void put(std::string str);
        int read();
        std::string read(int length);
    };

    class UdpSocketServer
    {
    private:
        int socketFD;       //The file descriptor for the socket
        struct sockaddr_in server_address;
        void listener();
        std::mutex allow_accept;
        bool accepting;
        virtual void worker(dev::UdpSocketServerConnection connection);
    public:
        UdpSocketServer();
        void start(int port);
        ~UdpSocketServer();
    };
}

#endif // UDPSOCKET_HPP
