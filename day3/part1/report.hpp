#ifndef __REPORT_H__
#define __REPORT_H__

#include <vector>
#include <string>
#include <algorithm>

struct Report
{
    Report();

    /// Proccesses one message from report
    /// @param rate Single binary string from whole report
    void add_rate(std::string rate);

    /// Generates gamma and epsilon based on data collected by all add_rate() 
    void generate();

    /// Returns gamma in decimal 
    int get_gamma() const {return convert(gamma);}

    /// Returns epsilon in decimal 
    int get_epsilon() const {return convert(epsilon);}

private:
    /// Converts binary string @p num to decimal  
    int convert(std::string num) const;

    /// Const value, lenght of one message
    enum con{size = 12};

    /// Holds quantity of ones for each column
    std::vector<int> ones;

    /// Holds quantity of zeros for each column
    std::vector<int> zeros;

    std::string gamma;
    std::string epsilon;
};

#endif
