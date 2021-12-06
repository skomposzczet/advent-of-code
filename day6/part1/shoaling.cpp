#include "shoaling.hpp"

void Shoaling::add_fish(std::string set)
{
    std::for_each(set.begin(), set.end(), [this](char c){if (isnum(c)) fishes.push_back(std::stoi(std::string(1,c))); });
}

void Shoaling::pass()
{
        // narybek
    int onfish = std::count_if(fishes.begin(), fishes.end(), [this](Fish & f){return f.pass();});

    if (onfish)
    {
        fishes.reserve(onfish);
        for (int i = 0 ; i < onfish ; i++)
            fishes.push_back(Fish());
    }
}

void Shoaling::pass(int n)
{
    for (int i = 0 ; i < n ; i++)
        pass();
}