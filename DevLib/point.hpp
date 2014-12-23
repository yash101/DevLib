#ifndef POINT_HPP
#define POINT_HPP
#include <cmath>
namespace dev
{
    template<typename T> class Point
    {
    private:
        T _x;
        T _y;
    public:
        Point(T x, T y) { _x = x; _y = y; }
        template<typename type> Point(dev::Point<type>&& pt) { _x = pt.getX(); _y = pt.getY(); }
        template<typename type> void operator=(dev::Point<type>& pt) { _x = pt.getX(); _y = pt.getY(); }

        T getX() { return _x; }
        T getY() { return _y; }
        template<typename Z> void setX(Z x) { _x = (T) x; }
        template<typename Z> void setY(Z y) { _y = (T) y; }

        template<typename type> bool operator==(dev::Point<type>& pt) { return _x == pt.getX() && _y == pt.getY(); }
        template<typename type> bool operator!=(dev::Point<type>& pt) { return _x != pt.getX() || _y != pt.getY(); }

        template<typename type> T distance(dev::Point<type>& pt)
            { return std::sqrt(((pt.getX() - _x) * (pt.getX - _x)) + ((pt.getY() - _y) * (pt.getY() - _y))); }
    };
}
#endif // POINT_HPP
