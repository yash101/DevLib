#ifndef PATHFINDING_HPP
#define PATHFINDING_HPP
#include <iostream>
#include <vector>
#include "../point.hpp"
#include "../Exceptions.hpp"

namespace dev
{
    namespace AStar
    {
        class Cell
        {
        public:
            //The grid location of this cell
            int x, y;
            //The G and H value. Used
            float G, H;
            //Is this location blocked?
            bool blocked;
            //A pointer to the parent! This has to be a pointer because we need to be able to set it to
            //the memory address of another cell in realtime!
            dev::AStar::Cell* parent;
            void setG(float val) { G = val; }
            void setH(float val) { H = val; }
            void setBlocked(bool val) { blocked = val; }
            float getG() { return G; }
            float getH() { return H; }
            float getF() { return G + H; }
            bool isBlocked() { return blocked; }
            Cell() : x(0), y(0), G(0.0), H(0.0), blocked(false) {}
            Cell(int locx, int locy) : x(locx), y(locy), G(0.0), H(0.0), blocked(false) {}
            Cell(dev::Point<int> pt) : x(pt.getX()), y(pt.getY()), G(0.0), H(0.0), blocked(false) {}
        };

        class Grid
        {
        private:
            std::vector<std::vector<dev::AStar::Cell> > _cells;
            int _width;
            int _height;
        public:
            Grid(int width, int height) : _cells(width, std::vector<dev::AStar::Cell>(height)), _width(width), _height(height) {}
            int getHeight() { return _height; }
            int getWidth() { return _width; }
            dev::AStar::Cell getCell(int x, int y) { if(isOnGrid(dev::Point<int>(x, y))) { return _cells[x][y]; } else { throw dev::AIException("Out of Bounds!"); } }
            bool isOnGrid(dev::Point<int> pt) { return pt.getX() >= 0 && pt.getX() <= _width && pt.getY() >= 0 && pt.getY() <= _height; }
            std::vector<dev::Point<int> > getNeighbors(dev::Point<int> pt);
        };

        std::vector<dev::Point<int> > generatePath(dev::AStar::Grid& grid, dev::Point<int> start, dev::Point<int> end);
    }
}
#endif // PATHFINDING_HPP
