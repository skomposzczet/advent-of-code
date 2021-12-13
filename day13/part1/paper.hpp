#ifndef __PAPER_H__
#define __PAPER_H__

#include <string>
#include <vector>
#include <algorithm>

#include "point.hpp"

class Paper
{
public:
    Paper() : f{-1} {}
    
    /// Gets line and proccesses it appropriately
    void get_line(std::string line);

    /// Folds dependently on axis
    void fold();

    /// @returns Final result
    int result() const {return points.size();}

private:
    std::vector<Point> points;

    int f;
    char w;

    // actual folders
    void foldx(int f);
    void foldy(int f);

};

#endif