#ifndef TCPSOCKET_HPP
#define TCPSOCKET_HPP
#include "../compat.hpp"

#ifdef POSIX
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#endif

#include <iostream>
#include <mutex>

#include "../Exceptions.hpp"

#define DEFAULT_TCP_ARRAY_LENGTH    1024    //bytes
namespace dev
{
    class TcpSocketServerConnection
    {
    public:
        //Elements to access!
        int connid;
        int c;

        //Constructors
        TcpSocketServerConnection() {}
        ~TcpSocketServerConnection() { close(connid); }

        //Functions
        void put(char byte);
        void put(std::string str);
        int read();
        std::string read(int length);
    };

    class TcpSocketServer
    {
    private:
        int socketFD;
        struct sockaddr_in address;
        void listener();
        virtual void worker(dev::TcpSocketServerConnection connection);
        std::mutex allow_accept;
        bool accepting;
    public:
        TcpSocketServer();
        void start(int port);
        ~TcpSocketServer();
    };
}

#endif // TCPSOCKET_HPP
