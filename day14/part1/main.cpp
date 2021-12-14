#include <iostream>
#include <fstream>
#include <string>

#include "polymer.hpp"

#define INPUTFILE "../input"

int main()
{
    std::ifstream file(INPUTFILE);
    if (!file.is_open())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    std::string buff;
    getline(file, buff);
    Polymer polymer(buff);

    while(getline(file, buff))
        polymer.add_pair(buff);

    polymer.insert(10);

    std::cout << polymer.result() << std::endl;
}