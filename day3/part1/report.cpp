#include "report.hpp"

Report::Report()
{
    ones = std::vector<int>(size,0);
    zeros = std::vector<int>(size,0);
    
    gamma.reserve(size);
    epsilon.reserve(size);
}

void Report::add_rate(std::string rate)
{
    for (int i = 0 ; i < static_cast<int>(rate.size()); i++)
    {
        if (rate.at(i) == '1')
            ones.at(i) += 1;
        else
            zeros.at(i) += 1;
    }
}

void Report::generate()
{
    for (int i = 0 ; i < static_cast<int>(ones.size()); i++)
    {
        if (ones.at(i) > zeros.at(i))
        {
            gamma.push_back('1');
            epsilon.push_back('0');
        }
        else
        {
            gamma.push_back('0');
            epsilon.push_back('1');
        }
    }
}

int Report::convert(std::string num) const
{   
    int ret = 0;

    std::for_each(num.begin(), num.end(), [&ret](char n){ret = 2*ret + (n == '1' ? 1 : 0); });

    return ret;
}