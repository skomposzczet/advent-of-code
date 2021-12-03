#ifndef __REPORT_H__
#define __REPORT_H__

#include <vector>
#include <string>
#include <algorithm>

struct Report
{
    Report();

    void add_rate(std::string rate);
    void generate();

    int get_gamma() const {return convert(gamma);}
    int get_epsilon() const {return convert(epsilon);}

private:
    int convert(std::string num) const;

    enum con{size = 12};

    std::vector<int> ones;
    std::vector<int> zeros;

    std::string gamma;
    std::string epsilon;
};

#endif
