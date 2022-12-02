#include <iostream>
#include <fstream>
#include <string>

#define INPUTFILE "../input"

#include "cave.hpp"

int main()
{
    std::ifstream file(INPUTFILE);
    if (!file.is_open())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    Cave cave;

    for (std::string buff ; getline(file, buff) ;)
        cave.add_line(buff);

    cave.make_grid();
    std::cout << cave.find_path() << std::endl;    
}