#include "http.hpp"
#include <cstring>
#include "../string.hpp"
#define HEND HTTP_LINE_ENDING

//Default constructor for the http server
dev::http_server::http_server() {}

void dev::http_server::worker(dev::TcpSocketServerConnection connection)
{
    try
    {
        http_session session;
        session.connection = connection;
        session.parse_request();
        session.prepare_request();
        request_handler(session);
        send_response(session);
    }
    catch(std::exception& e)
    {
        std::cout << "Error while processing request! what() -> " << e.what() << std::endl;
    }
}

void dev::http_session::prepare_request()
{
    headers["content-type"] = "text/html";
    headers["server"] = "DevLibWeb/2.0";
    status_code = 200;
}

void dev::http_session::parse_request()
{
    //Determine the request type.
    std::string method = connection.getline(' ');
    if(method == "GET") { request_type = GET; }
    else if(method == "POST") { request_type = POST; }
    else if(method == "HEAD") { request_type = HEAD; }
    else { throw dev::HTTPException("Unknown HTTP Method!"); }

    //Determine the path the client is requesting
    path = dev::trim(connection.getline(' '));

    //Determine the protocol the client wants us to use
    protocol = dev::trim(connection.getline("\r\n"));

    //Download the rest of the request header
    std::string buffer;
    while(true)
    {
        char x = connection.read(1)[0];
        buffer += x;
        if(buffer.size() >= 4)
        {
            if(buffer.substr(buffer.size() - 4, buffer.size()) == "\r\n\r\n")
            {
                break;
            }
        }
    }

    std::stringstream in(buffer);
    //Get the lines out of the request
    while(std::getline(in, buffer, '\n'))
    {
        //Process each line and add it in!
        if(dev::charPos(buffer, ':') != -1)
        {
            std::string key = dev::tolower(buffer.substr(0, dev::charPos(buffer, ':')));
            std::string value = buffer.substr(dev::charPos(buffer, ':') + 1, buffer.size() - 1);
            if(std::isspace(value[0])) { value = value.substr(1, value.size()); }
            incoming_headers[key] = value;
        }
    }

    if(dev::charPos(path, '?') != -1)       //Ensure that there is an actual query to process
    {
        std::string query = path.substr(dev::charPos(path, '?') + 1, path.size());
        path = path.substr(0, dev::charPos(path, '?'));

        std::stringstream x(query);
        while(std::getline(x, buffer, '&')) //Explode the query into it's different parts!
        {
            std::stringstream z(buffer);
            std::string key, value;
            std::getline(z, key, '=');
            std::getline(z, value);
            if(key != "")
            {
                get[key] = dev::urldecode(value);
                queries[key] = dev::urldecode(value);
            }
        }
    }

    //Check if we recieved any data in the POST (get the joke there?)
    if(request_type == POST)
    {
        int length = std::atoi(incoming_headers["content-length"].c_str());
        std::string postvars;
        //Download the POST data
        for(int i = 0; i < length; i++)
        {
            postvars += (char) connection.read();
        }

        std::stringstream x(postvars);
        while(std::getline(x, buffer, '&')) //Explode the query into it's different parts!
        {
            std::stringstream z(buffer);
            std::string key, value;
            std::getline(z, key, '=');
            std::getline(z, value);
            if(key != "")
            {
                post[key] = dev::urldecode(value);
                queries[key] = dev::urldecode(value);
            }
        }
    }
}

//Sends the response back to the client so it can enjoy!
void dev::http_server::send_response(dev::http_session& session)
{
    //Send first line. The response shall be send now!
    session.connection.put("HTTP/1.0 " + dev::toString(session.status_code) + " " + dev::http_status(session.status_code) + HEND);
    for(std::unordered_map<std::string, std::string>::const_iterator it = session.headers.begin(); it != session.headers.end(); ++it)
    {
        session.connection.put(it->first + ": " + it->second + HEND);
    }
    session.connection.put("content-length: " + dev::toString(session.response.size()) + HEND);
    session.connection.put(HEND);
    session.connection.put(session.response);
    session.connection.close_socket();
}

//To be overwritten
void dev::http_server::request_handler(dev::http_session& session)
{
    session.response = "This web server is not for direct use!";
}
