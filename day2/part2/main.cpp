#include <iostream>
#include <string>
#include <fstream>

#define INPUTFILE "../input"

struct Coords
{
    Coords() :aim{0}, hor{0}, dep{0} {}
    int aim;
    int hor;
    int dep;

    void f(int n) {hor+=n; dep+=(aim*n);}
    void d(int n) {aim+=n;}
    void u(int n) {aim-=n;}
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
                coords.f(num);
                break;
            case 'u':
                coords.u(num);
                break;
            case 'd':
                coords.d(num);
                break;
        }
    }
    
    std::cout << coords.dep * coords.hor << std::endl;
}