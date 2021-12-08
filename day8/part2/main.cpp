#include <iostream>
#include <fstream>
#include <string>

#include "entry.hpp"

#define INPUTFILE "../input"

int main()
{
    std::ifstream file(INPUTFILE);
    if (!file.is_open())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    Entry entry;

    for (std::string buff ; getline(file, buff) ; )
        entry.getdata(buff);

    std::cout << entry.result() << std::endl;
}