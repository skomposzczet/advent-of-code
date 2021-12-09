#ifndef __HMAP_HPP__
#define __HMAP_HPP__

#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

class Hmap
{
public:
    /// Default ctor
    Hmap() : res{0} {}

    /// Adds row @p str to row vector
    void add_row(std::string str);

    /// Analyzes map
    void analyze();

    /// @returns Final result
    int result() const { return res; }

private:
    std::vector<std::string> rows;
    int res;

    /// @returns True if point is lowest in its neighbourhood
    bool is_lowest(int x, int y) const;

    /// @return int represented by char
    static int cti(char c) {return c-48;} 
};

#endif