#ifndef __CAVERN_H__
#define __CAVERN_H__

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "point.hpp"

class Cavern
{
using Row = std::vector<int>;

public:
    Cavern() : res{0} {grid.reserve(size);}

    /// Transforms string @p str to Row
    void add_row(std::string str);

    /// Increases enegery @p n times
    void inc_energy(int n);

    /// @returns final result
    int result() const {return res; }

private:
    enum s{size = 10};

    /// Final result
    int res;

    /// Vector of energies of each octopus
    std::vector<Row> grid;

    /// Vectors to each neighbour of point
    const std::vector<Point> neighbourhood{{1,1}, {1,0},{1,-1},{-1,0},{-1,-1},{-1,1},{0,1},{0,-1}};

    /// Increases energy by 1 for whole grid
    void inc_energy();

    /// Increases energy by 1 for @p p (raises neighbours if neccessary)
    void raise(Point p);

    /// @returns True if point is in range
    bool iir(Point p);

    /// Imitates array behaviour
    int & at(Point p) {return grid.at(p.gety()).at(p.getx());}
};

#endif