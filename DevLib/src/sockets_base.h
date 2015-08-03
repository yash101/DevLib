#ifndef SOCKETS_BASE_H
#define SOCKETS_BASE_H
#include <exception>
#include "definitions.h"
namespace dev
{
  class Exception : public std::exception
  {
  protected:
    const char* _message;
    const int _code;
  public:
    Exception();
    Exception(const char* message);
    Exception(const int _code);
    Exception(const char* message, const int code);
    ~Exception() throw();

    virtual const char* what() const throw();
    const int code();
  };
}
#endif
