#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
#include <exception>
#include <string>
namespace dev
{
    class SocketException : public std::exception
    {
    private:
        std::string _message;
    public:
        SocketException(std::string message) : _message(message) {}
        virtual const char* what() const throw() { return _message.c_str(); }
    };

    class AIException : public std::exception
    {
    private:
        std::string _message;
    public:
        AIException(std::string message) : _message(message) {}
        virtual const char* what() const throw() { return _message.c_str(); }
    };
}
#endif // EXCEPTIONS_HPP
