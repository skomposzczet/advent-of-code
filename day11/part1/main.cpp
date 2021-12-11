#include <iostream>
#include <fstream>
#include <string>

#include "cavern.hpp"

#define INPUTFILE "../input"

int main()
{
    std::ifstream file(INPUTFILE);
    if (!file.is_open())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    Cavern cavern;

    for (std::string buff ; getline(file, buff) ; )
        cavern.add_row(buff);

    cavern.inc_energy(100);

    std::cout << cavern.result() << std::endl;
}