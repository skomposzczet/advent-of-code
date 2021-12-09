#ifndef __HMAP_HPP__
#define __HMAP_HPP__

#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <numeric>

#include "point.hpp"

class Hmap
{
public:
    /// Default ctor
    Hmap() {basins.reserve(4);}

    /// Adds row @p str to row vector
    void add_row(std::string str) {rows.push_back(str);}

    /// Analyzes map
    void analyze();

    /// @returns Final result
    int result() const;

private:
    std::vector<std::string> rows;
    std::vector<int> basins;

    /// Vectors with which every neighbour of point can be created
    const std::vector<Point> neighbour_vectors{Point(0,-1), Point(-1, 0), Point(1,0), Point(0,1)};


    /// @returns True if point is lowest in its neighbourhood
    bool is_lowest(Point p) const;

    /// Calculates size of basin
    int detect_basin(Point p) { std::vector<Point> coords; return detect_basin(p,coords);};
    int detect_basin(Point p, std::vector<Point> & coords);

    /// Adds basin size if its in top 3 greatest sizes
    void add_basin(const int b);

    /// @returns True if point is in range of map
    bool iir(const int x, const int y) const;
    bool iir(const Point p) const { return iir(p.getx(), p.gety()); }

    /// @returns Char from point @p p
    char get_char(const Point p) const {return rows.at(p.gety()).at(p.getx()); }
};

#endif