#include <iostream>
#include <fstream>
#include <string>

#define INPUTFILE "../input"
#define DAYS 80

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

    shoaling.pass(DAYS);

    std::cout << shoaling.result() << std::endl;

    file.close();
}