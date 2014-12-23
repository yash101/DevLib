#include <iostream>
#include "DevLib/vector.hpp"
#include <vector>
#include <stdio.h>
#include "DevLib/logger.hpp"
#include "DevLib/math.hpp"
#include "DevLib/string.hpp"
#include "DevLib/math.hpp"
#include "DevLib/point.hpp"
#include "DevLib/filesystem.hpp"
#include "DevLib/Sockets/tcpsocket.hpp"
#include "DevLib/Servers/WebServer.hpp"
#include "DevLib/ai/Pathfinding.hpp"
#include <string>
#include <chrono>
#include <thread>
#include <signal.h>
#include <random>

using namespace std;

class DevServer : public dev::TcpSocketServer
{
    void worker(dev::TcpSocketServerConnection connection)
    {
        connection.put("Hello, person! New server here! Time to get started coding! :D");
        //connection.put(connection.read(64));
    }
};

class DWeb : public dev::HttpServer
{
    void request_handler(dev::HttpServerRequest& request)
    {
        std::stringstream o;
        o << "<html><head><title>Hello World!</title></head><body>" << std::endl;
        o << "<h1>Queries</h1>" << std::endl;
        o << "<table>" << std::endl;
        for(dev::strmap::const_iterator it = request.queries.begin(); it != request.queries.end(); ++it)
        {
            o << "<tr><td>" << it->first << "</td><td>" << it->second << "</td></tr>" << std::endl;
        }
        o << "</table>" << std::endl;
        o << "</body></html>" << std::endl;
        request.response = o.str();
    }
};

void handle(int x) { exit(0); }

struct cell
{
    int x, y
    float G, H;
    bool blocked;
    bool start;
    bool end;
    cell* parent;
};

bool isOnGrid(int x, int y) { return x >= 0 && x <= 16 && y >= 0 && y <= 16; }

int main()
{
    //Path planning :D
    cell cells[16][16];
    std::vector<cell> open;
    std::vector<cell> closed;

    std::default_random_engine rng;
    std::uniform_int_distribution<int> dist(0, 3);
    std::uniform_int_distribution<int> dist2(0, 16);
    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            cells[i][j].start = false;
            cells[i][j].end = false;
            cells[i][j].x = i;
            cells[i][j].y = j;
            if(dist2(rng) > 1) { cells[i][j].blocked = false; } else { cells[i][j].blocked = true; }
        }
    }

    int startX = dist2(rng);
    int startY = dist2(rng);
    int endX = 0;
    int endY = 0;
    do
    {
        endX = dist2(rng);
        endY = dist2(rng);
    }
    while(startX != endX && startY != endY);

    cells[startX][startY].start = true;
    cells[endX][endY].end = true;

    std::cout << "START: " << std::endl;
    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            std::cout << (int) cells[i][j].blocked << ' ';
        }
        std::cout << std::endl;
    }

    if(isOnGrid(startX + 1, startY)) { open.push_back(cells[startX + 1][startY]); }
    if(isOnGrid(startX - 1, startY)) { open.push_back(cells[startX - 1][startY]); }
    if(isOnGrid(startX, startY + 1)) { open.push_back(cells[startX][startY + 1]); }
    if(isOnGrid(startX, startY - 1)) { open.push_back(cells[startX][startY - 1]); }

    return 0;

    //////////////////
    //Signal handlers are there so we can properly GC before exiting. Otherwise, ports stay open until the kernel comes along, killing them!
    signal(SIGINT, handle);
    signal(SIGTERM, handle);
    signal(SIGSEGV, handle);
    //dev::TcpSocketServer sock;
    DevServer sock;
    sock.start(8000);
    DWeb web;
    web.start(8001);
    while(true) { std::this_thread::sleep_for(std::chrono::seconds(2)); }
    return 0;
}
