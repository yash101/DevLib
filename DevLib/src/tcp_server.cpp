#include "sockets_base.h"
#include "tcp_server.h"

#include <new>
#include <string.h>
#include <thread>
#include <sstream>

#ifndef _WIN32
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <unistd.h>
#endif

#define TCP_SERVER_ERROR_ALREADY_RUNNING -1
#define TCP_SERVER_ERROR_MULTI_ALLOC -2
#define TCP_SERVER_ERROR_SOCKET_CREATE -3
#define TCP_SERVER_ERROR_SOCKET_BIND -4

//This function is the initializer for the TCP server object. It sets up default values.
dev::TcpServer::TcpServer() :
  _address(NULL),
  _port(0),
  _started(false)
{}

//This function destroys the TCP server object
dev::TcpServer::~TcpServer()
{
  if(_address != NULL)
    delete (struct sockaddr_in*) _address;
  close(_fd);
}

//This function starts the TCP server
int dev::TcpServer::start(int port)
{
  //Check to make sure the server has not been started yet. If it hasn't, flag it as started and
  //  perform boot loading.
  if(_started)
    return TCP_SERVER_ERROR_ALREADY_RUNNING;
  else
    _started = true;

  //Save the bound port to the object (just for safe keeping)
  _port = port;

  try
  {
    //Check fo make sure we didn't already allocate the address structure. If we didn't, allocate it.
    //  Otherwiser, return because someone's already allocated.
    if(_address != NULL)
      return TCP_SERVER_ERROR_MULTI_ALLOC;
    _address = (void*) new struct sockaddr_in;
  }
  catch(std::bad_alloc& e)
  {
    //Return error code in case we were unable to allocate enough space for the address pointer
    return DEVLIB_ERROR_BAD_ALLOC;
  }

  //Clear the memory allocated towards the socket address structure.
  memset((char*) _address, 0, sizeof(struct sockaddr_in));

  //Set up the address structure and prepare to create the socket.
  ((struct sockaddr_in*) _address)->sin_family = AF_INET;
  ((struct sockaddr_in*) _address)->sin_port = htons(_port);
  ((struct sockaddr_in*) _address)->sin_addr.s_addr = INADDR_ANY;

  //Create the socket and check to ensure success
  _fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if(_fd < 0) return TCP_SERVER_ERROR_SOCKET_CREATE;

  //Bind the socket to the address structure
  if(bind(_fd, (struct sockaddr*) _address, sizeof(struct sockaddr_in)) < 0)
    return TCP_SERVER_ERROR_SOCKET_BIND;

  //Begin listening for incoming connections. We will keep a queue depth of 3. That should easily
  //  be plenty.
  listen(_fd, 3);

  accepter();
}

void dev::TcpServer::accepter()
{
  //This holds the size of the sockaddr_in struct. We need to pass a pointer to this.
  static int c = sizeof(struct sockaddr_in);
  while(true)
  {
    //Create a NULL TcpServerConnection pointer
    dev::TcpServerConnection* connection = NULL;
    try
    {
      //Attempt to allocate a new TcpServerConnection
      connection = new dev::TcpServerConnection;
    }
    catch(std::bad_alloc& e)
    {
      //Sleep 25 milliseconds. Perhaps some resources might have been freed somewhere.
      std::this_thread::sleep_for(std::chrono::milliseconds(25));
      //Restart
      continue;
    }

    //Accept the connection. If failed, delete the connection and restart
    if((connection->_fd = accept(_fd, (struct sockaddr*) connection->_address, (socklen_t*) &c)) < 0)
    {
      delete connection;
      continue;
    }

    //Give the server a pointer to this object. Just there for general purpose ;)
    connection->server = this;

    try
    {
      //We use the connection in a new thread.
      std::thread(&dev::TcpServer::connector, this, connection).detach();
    }
    catch(std::exception& e)
    {
      delete connection;
      continue;
    }
  }
}

void dev::TcpServer::connector(dev::TcpServerConnection* connection)
{
  try
  {
    worker(connection);
  }
  catch(std::exception& e)
  {}

  delete connection;
}

void dev::TcpServer::worker(dev::TcpServerConnection* connection)
{
  connection->write("Hello World! You've got the TCP server running! Now, read the docs on how to inherit from this class and make it do whatever you want!\n");
  connection->write("Please enter your name:\n$ ");
  char buffer[2048];
  buffer[2047] = '\0';
  connection->readline(buffer, '\n', 2048);
  connection->write("Hello, ");
  connection->write(buffer);
  connection->write("!\n");
}

//TCP Server Session
dev::TcpServerConnection::TcpServerConnection() :
  _fd(0),
  _address((void*) new struct sockaddr_in)
{}

dev::TcpServerConnection::~TcpServerConnection()
{
  close(_fd);
  delete (struct sockaddr_in*) _address;
}

//This function reads from the socket
int dev::TcpServerConnection::read(char* buffer, size_t len)
{
  return ::recv(_fd, (void*) buffer, len, 0);
}

int dev::TcpServerConnection::read(char& byte)
{
  return ::recv(_fd, (void*) &byte, sizeof(char), 0);
}

char dev::TcpServerConnection::read()
{
  char ch;
  int i;
  if(i = ::recv(_fd, (void*) &ch, sizeof(char), 0) <= 0)
    throw dev::Exception("TcpServer recv() failure", i);
  return ch;
}

int dev::TcpServerConnection::write(char* data, size_t len)
{
  return ::send(_fd, (void*) data, len, 0);
}

int dev::TcpServerConnection::write(std::string str)
{
  return ::send(_fd, (void*) str.c_str(), str.size(), 0);
}

int dev::TcpServerConnection::write(char byte)
{
  return ::send(_fd, (void*) &byte, sizeof(char), 0);
}

std::string dev::TcpServerConnection::readline(char end, size_t maxlen)
{
  size_t iter = 0;
  std::stringstream s;
  while(iter++ < maxlen)
  {
    char ch;
    ::recv(_fd, &ch, sizeof(char), 0);
    if(ch == end) return s.str();
    s << (char) ch;
  }

  return s.str();
}

bool dev::TcpServerConnection::readline(char* buffer, char end, size_t len)
{
  if(len == 0) return false;
  char* st = buffer;
  size_t rd = 0;
  while(rd < len - 1)
  {
    if(::recv(_fd, (void*)(st), sizeof(char), 0) <= 0)
    {
      (*--st) = '\0';
      return false;
    }
    if(*st == end)
    {
      *st = '\0';
      return true;
    }
    ++st;
  }
  //Should never reach here unless something's awry
  return false;
}
