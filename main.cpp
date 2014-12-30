#include "DevLib/Servers/WebServer.hpp"
#include <chrono>
#include <thread>
int main(int argc, char** argv)
{
    dev::HttpServerInALambda http([](dev::HttpServerRequest& request)
    {
        request.response = "<html><body><h1>It Works!</h1></body></html>";
    });

    http.start(12345);
    std::cout << "Server Has been Started!" << std::endl;
    while(true) { std::this_thread::sleep_for(std::chrono::seconds(10)); }
    return 0;
}
