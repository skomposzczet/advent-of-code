#include <iostream>
#include <fstream>
#include <string>

#include "ventList.hpp"

#define INPUTFILE "../input"

int main()
{
    std::ifstream file(INPUTFILE);
    if (!file.is_open())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    VentList vl;

    for (std::string buff ; getline(file, buff) ; )
        vl.add_line(buff);

    vl.make_grid();
    
    std::cout << vl.result() << std::endl;
    
}