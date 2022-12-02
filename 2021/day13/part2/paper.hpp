#ifndef __PAPER_H__
#define __PAPER_H__

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "point.hpp"

class Paper
{
public:
    Paper() {}
    
    /// Gets line and proccesses it appropriately
    void get_line(std::string line);

    /// Prints final result (XD)
    /// @warning WTF
    /// @attention wanted to do it in ncurses but i have too little time lately :<
    void result() const;

private:
    std::vector<Point> points;

    // actual folders
    void foldx(int f);
    void foldy(int f);

};

#endif