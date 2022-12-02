#ifndef __POINT_H__
#define __POINT_H__

class Point
{
public:
    Point(int _x = 0, int _y = 0) : x{_x}, y{_y} {}
    ~Point() {}

    Point operator+(const Point sec) const { return Point(x+sec.x,y+sec.y); }

    bool operator==(const Point sec) const { return (x==sec.x && y==sec.y); }

    int getx() const {return x;}
    int gety() const {return y;}

    int & getx() {return x;}
    int & gety() {return y;}

private:
    int x;
    int y;
};

#endif