#ifndef __REPORT_H__
#define __REPORT_H__

#include <vector>
#include <string>
#include <algorithm>

struct Report
{
    Report();

    /// Adds single message
    void add_rate(std::string str);

    /// Does calculations and reduce vector to one single string
    void proccess();

    /// Returns first (and should be only) value from oxygen vector
    int get_oxygen() const { return convert(oxygen.at(0));}
    /// Returns first (and should be only) value from co2 vector
    int get_co2() const { return convert(co2.at(0));}

private:
    std::vector<std::string> oxygen;
    std::vector<std::string> co2;

    int convert(std::string num) const;
    void revert(char & n) const { n = (n=='1' ? '0' : '1'); }

    void proccess(std::vector<std::string> & vec, bool rev = false);
};

#endif
