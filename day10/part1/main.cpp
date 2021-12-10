#include <iostream>
#include <fstream>
#include <string>

#include "line.hpp"

#define INPUTFILE "../input"

int main()
{
    std::ifstream file(INPUTFILE);
    if (!file.is_open())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    Line line;

    for (std::string buff ; getline(file, buff) ; )
        line.proccess_line(buff);

    std::cout << line.result() << std::endl;
}