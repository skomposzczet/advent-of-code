#ifndef __CAVE_H__
#define __CAVE_H__

#include <string>
#include <vector>
#include <algorithm>

#include "point.hpp"

class Cave
{
public:
    Cave() {}

    void add_line(std::string line);

    void make_grid();

    int find_path(){return find_path(Point(), 48-value(Point()));}

    int result();

private:
    std::vector<std::string> grid;

    std::vector<Point> neighbours{{1,0}, {0,1}};

    Point end;


    bool range(const Point & p) const;

    int value(const Point & p) const;

    int find_path(Point starting_point, int current_total);

    // static fmin(int a, int b) {return (a>b?b:a);}
};

#endif