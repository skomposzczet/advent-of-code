#include <iostream>
#include <string>
#include <fstream>

#define INPUTFILE "../input"

struct Coords
{
    Coords() :x{0}, y{0} {}
    int x;
    int y;

    void addx(int num) {x+=num;}
    void addy(int num) {y+=num;}
};

int main()
{
    std::ifstream file(INPUTFILE);
    if (!file.is_open())
    {
        std::cout << "file not found" << std::endl;
        return 1;
    }

    Coords coords;
    std::string buff;

    while(getline(file, buff))
    {   
        int num = std::stoi(buff.substr(buff.find_last_of(' ')+1,1));
        switch (buff.at(0))
        {
            case 'f':
                coords.addx(num);
                break;
            case 'u':
                coords.addy(-num);
                break;
            case 'd':
                coords.addy(num);
                break;
        }
    }
    
    std::cout << coords.y * coords.x << std::endl;
}