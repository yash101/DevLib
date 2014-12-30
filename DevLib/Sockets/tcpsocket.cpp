#include "tcpsocket.hpp"
#include <arpa/inet.h>
#include <thread>
#include <iostream>
#include <string.h>
#include "../string.hpp"

//Constructor
dev::TcpSocketServer::TcpSocketServer() : accepting(false) {}

//Sets the listening port and starts the server.
void dev::TcpSocketServer::start(int port)
{
    //Create the socket file descriptor
    socketFD = socket(AF_INET, SOCK_STREAM, 0);
    //Verify that we were able to create the socket server and throw and exception if we didn't
    if(socketFD < 0) { throw SocketException("Unable to Create Socket!"); }
    //Clear the address structure.
    memset((char*) &address, 0, sizeof(address));
    //Set up the address and prepare to start serving
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(port);
    //Bind to the address/port specified. If this isn't successful, an exception will be thrown
    if(bind(socketFD, (struct sockaddr*) &address, sizeof(address)) < 0) { throw SocketException("Unable to bind to socket!"); }
    //Begin listening in the socket
    listen(socketFD, 3);
    //Launch a new thread to listen for us. This thread detaches to allow this function to quite afterwards
    std::thread(&dev::TcpSocketServer::listener, this).detach();
}

//Processes Requests. This is just the default connection handler. You are supposed to create your own.
//This just sends back to the client what to do to get started.
void dev::TcpSocketServer::worker(dev::TcpSocketServerConnection connection)
{
    connection.put("Hello World! You have successfully created a DevLib TcpSocketServer! Now, create a new class that extends off this!\n");
    connection.put("Overwrite the dev::TcpSocketServer::worker(dev::TcpSocketServerConnection) and add your code.\n");
    connection.put("dev::TcpSocketServerConnection is the class which allows you to interact with the socket connection!\n");
}

void dev::TcpSocketServer::vhost(int connectionid)
{
    dev::TcpSocketServerConnection connection;
    connection.c = sizeof(struct sockaddr_in);
    connection.connid = connectionid;
    worker(connection);
}

void dev::TcpSocketServer::listener()
{
    while(true)
    {
        int fd;
        int c = sizeof(struct sockaddr_in);
        fd = accept(socketFD, (struct sockaddr*) &address, (socklen_t*) &c);
        if(fd < 0) { std::cout << "Failed accepting new connection!" << std::endl; continue; }
        std::thread(&dev::TcpSocketServer::vhost, this, fd).detach();
    }
}

//Send a character to the client
void dev::TcpSocketServerConnection::put(std::string str)
{
    write(connid, str.c_str(), str.size());
}

//Send a character to the client
void dev::TcpSocketServerConnection::put(char byte)
{
    put(dev::toString(byte));
}

std::string dev::TcpSocketServerConnection::read(int length)
{
    char* x = new char[length];         //Allocate some memory to read into
    //Attempt to read from the socket. Throw and exception otherwise
    if(recv(connid, x, length, 0) < 0) { throw dev::SocketException("Unable to read from socket!"); }
    //Convert what we recieved to an std::string so we have automatic GC.
    std::string z = dev::toString(x);
    //Deallocate the memory that we previously allocated
    delete[] x;
    //Return the string!
    return z;
}

//This reads a char from the client. Note that we just used the string read command, but only read a single byte
//Note that you will need to cast to a char because we are returning int for platform compatibility
int dev::TcpSocketServerConnection::read()
{
    return (int) read(1)[0];
}

//This is the destructor. Here, all we have to do is close the socket. Kudos for using C++ containers which automatically perform GC! ;)
dev::TcpSocketServer::~TcpSocketServer()
{
    close(socketFD);
}
