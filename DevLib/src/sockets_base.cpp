#include "sockets_base.h"

dev::Exception::Exception() :
  _message("An exception was encountered during program execution"),
  _code(0)
{}

dev::Exception::Exception(const char* message) :
  _message(message),
  _code(0)
{}

dev::Exception::Exception(const int code) :
  _message("An exception was encountered during program execution"),
  _code(code)
{}

dev::Exception::Exception(const char* message, const int code) :
  _message(message),
  _code(code)
{}

dev::Exception::~Exception() throw()
{}

const char* dev::Exception::what() const throw()
{
  return _message;
}

const int dev::Exception::code()
{
  return _code;
}
