#include <iostream>
#include <fstream>
#include <string>

#include "heightmap.hpp"

#define INPUTFILE "../input"

int main()
{
    std::ifstream file(INPUTFILE);
    if (!file.is_open())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    Hmap hmap;

    for (std::string buff ; getline(file, buff) ; )
        hmap.add_row(buff);

    hmap.analyze();

    std::cout << hmap.result() << std::endl;
    
}