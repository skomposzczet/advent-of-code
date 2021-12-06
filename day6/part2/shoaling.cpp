#include "shoaling.hpp"

void Shoaling::add_fish(std::string set)
{
    std::for_each(set.begin(), set.end(), [this](char c){if (isnum(c)) fishes.push_back(c-48); });
}

long long Shoaling::result(int dtp)
{
    std::vector<long long> days(9,0);
    std::for_each(fishes.begin(), fishes.end(), [&days](long long n){ ++days[n]; } );

    for (int i = 0 ; i < dtp ; i++)
    {
        std::rotate(days.begin(), days.begin()+1 ,days.end());
        days[6] += days[8];
    }

    return std::accumulate(days.begin(), days.end(), 0ll);
}