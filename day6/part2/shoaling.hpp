#ifndef __SHOALING_H__
#define __SHOALING_H__

#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

class Shoaling
{
public:
    Shoaling(){}

    /// Adds fishes to vector extracting their timers from string @p set
    void add_fish(std::string set);

    /// @returns Result
    long long result(int dtp);

private:
    std::vector<int> fishes;

    bool isnum(char c) {return (c>='0'&&c<='9');}
};

#endif