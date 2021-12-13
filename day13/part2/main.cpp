#include <iostream>
#include <fstream>
#include <string>

#include "paper.hpp"

#define INPUTFILE "../input"

int main()
{
    std::ifstream file(INPUTFILE);
    if (!file.is_open())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    Paper paper;

    for(std::string buff ; getline(file, buff) ; )
        paper.get_line(buff);

    paper.result();
}