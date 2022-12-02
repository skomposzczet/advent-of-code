#include <iostream>
#include <fstream>
#include <string>

#define INPUTFILE "../input"
#define DAYS 256

#include "shoaling.hpp"

int main()
{
    std::ifstream file(INPUTFILE);
    if (!file.is_open())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    Shoaling shoaling;

    std::string buff;
    getline(file, buff);

    shoaling.add_fish(buff);

    std::cout << shoaling.result(DAYS) << std::endl;

    file.close();
}