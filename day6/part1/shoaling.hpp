#ifndef __SHOALING_H__
#define __SHOALING_H__

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#include "fish.hpp"

class Shoaling
{
public:
    Shoaling(){}

    /// Adds fishes to vector extracting their timers from string @p set
    void add_fish(std::string set);

    /// Simulates passing one day
    void pass();

    /// Simulates passing @p n days
    void pass(int n);

    /// @returns Result
    int result() const { return fishes.size(); }

private:
    std::vector<Fish> fishes;

    bool isnum(char c) {return (c>='0'&&c<='9');}
};

#endif