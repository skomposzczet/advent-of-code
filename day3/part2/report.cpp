#include "report.hpp"

Report::Report()
{

}

void Report::add_rate(std::string str)
{
    oxygen.push_back(str);
    co2.push_back(str);
}

void Report::proccess()
{
    proccess(oxygen);
    proccess(co2, true);
}

void Report::proccess(std::vector<std::string> & vec, bool rev)
{
    for (int ind = 0 ; vec.size() > 1; ind++)
    {
        int zeros = 0;
        int ones = 0;
        for (int i = 0 ; i < static_cast<int>(vec.size()) ; i++)
            vec.at(i).at(ind) == '1' ? ones++ : zeros++;

        char to_remove = (zeros>ones ? '1' : '0');
        if (rev) 
            revert(to_remove); 
        vec.erase(std::remove_if(vec.begin(), vec.end(), [&](std::string str){ return (str.at(ind) == to_remove);}), vec.end());         
    }   
}

int Report::convert(std::string num) const
{   
    int ret = 0;

    std::for_each(num.begin(), num.end(), [&ret](char n){ret = 2*ret + (n == '1'); });

    return ret;
}