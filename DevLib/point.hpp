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
        //Constructors
        //-/Default constructor. Takes X and Y
        Point(T x, T y) { _x = x; _y = y; }
        //-/Move constructor
        template<typename type> Point(dev::Point<type>&& pt) { _x = pt.getX(); _y = pt.getY(); }
        //-/Assignment operator construction
        template<typename type> void operator=(dev::Point<type>& pt) { _x = pt.getX(); _y = pt.getY(); }

        //Getter's and Setter's
        T getX() { return _x; }
        T getY() { return _y; }
        template<typename Z> void setX(Z x) { _x = (T) x; }
        template<typename Z> void setY(Z y) { _y = (T) y; }

        //Comparison operators
        template<typename type> bool operator==(dev::Point<type>& pt) { return _x == pt.getX() && _y == pt.getY(); }
        template<typename type> bool operator!=(dev::Point<type>& pt) { return _x != pt.getX() || _y != pt.getY(); }

        //Calculate the distance between a different point
        template<typename type> T distance(dev::Point<type>& pt)
            { return std::sqrt(((pt.getX() - _x) * (pt.getX - _x)) + ((pt.getY() - _y) * (pt.getY() - _y))); }
    };

    template<typename T> dev::Point<T> toPolar(dev::Point<T> p)
    {
        return dev::Point<T>((p.getX() * p.getX()) + (p.getY() * p.getY()), std::atan(p.getY() / p.getX()));
    }

    template<typename T> dev::Point<T> toRectangular(dev::Point<T> p)
    {
        return dev::Point<T>(p.getX() * std::cos(p.getY()), p.getY() * std::sin(p.getY()));
    }
}
#endif // POINT_HPP
