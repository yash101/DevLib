#include "DevLib/Servers/http.hpp"
#include "DevLib/Servers/WebServer.hpp"
#include "DevLib/string.hpp"
#include "DevLib/Sockets/tcpclient.hpp"
#include <chrono>
#include <thread>
class h : public dev::http_server
{
    void request_handler(dev::http_session& session)
    {
        std::string out;
        out += "<html><body>";
        out += "<p>Hello W0rld!</p>";
        out += "<form action=\"/\" method=\"POST\"><input type=\"text\" name=\"hello_world\"><input type=\"submit\" value=\"Go\"></form>";
        out += "<p>GET: </p>";
        for(std::unordered_map<std::string, std::string>::const_iterator it = session.get.begin(); it != session.get.end(); ++it)
        {
            out += "<p>Recieved: [" + it->first + "] &rarr; [" + it->second + "]</p>";
        }
        out += "<p>POST: </p>";
        for(std::unordered_map<std::string, std::string>::const_iterator it = session.post.begin(); it != session.post.end(); ++it)
        {
            out += "<p>Recieved: [" + it->first + "] &rarr; [" + it->second + "]</p>";
        }
        out += "<p>REQUEST: </p>";
        for(std::unordered_map<std::string, std::string>::const_iterator it = session.queries.begin(); it != session.queries.end(); ++it)
        {
            out += "<p>Recieved: [" + it->first + "] &rarr; [" + it->second + "]</p>";
        }
        out += "<p>REQUEST HEADERS: </p>";
        for(std::unordered_map<std::string, std::string>::const_iterator it = session.incoming_headers.begin(); it != session.incoming_headers.end(); ++it)
        {
            out += "<p>Recieved: [" + it->first + "] &rarr; [" + it->second + "]</p>";
        }
        out += "<p>Path: [" + session.path + "]</p>";
        out += "<p>Protocol: [" + session.protocol + "]</p>";
        out += "<p>Returned Status Code: " + dev::toString(session.status_code) + "</p>";
        out += "</body></html>";
        session.response = out;
    }
};

int main(int argc, char** argv)
{
    h().start(12345);

    while(true) { std::this_thread::sleep_for(std::chrono::seconds(10)); }
    return 0;
}
