#ifndef __VENTLIST_H__
#define __VENTLIST_H__

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#include "line.hpp"

class VentList
{
public:
    VentList() :maxx{0}, maxy{0} {}

    /// Adds line 
    void add_line(std::string str);

    /// Generates grid and marks it with lines
    void make_grid();

    /// Counts points and return result
    int result();

private:
    std::vector<Line> lines;
    std::vector<int> grid;
    int maxx;
    int maxy;

    /// Pushes all points from line onto grid
    void ppg(Line & l);

    /// @returns Greater integer
    static int max(int a, int b){return(a>b?a:b);}
};

#endif