#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "report.hpp"

#define INPUTFILE "../input"


int main()
{
    std::ifstream file(INPUTFILE);
    if(!file.is_open())
    {
        std::cout << "File not found" << std::endl;
        return 1;
    }

    Report report;

    for (std::string buff ; getline(file, buff) ; )
        report.add_rate(buff);

    report.generate();
    
    std::cout << report.get_epsilon() * report.get_gamma() << std::endl;
}