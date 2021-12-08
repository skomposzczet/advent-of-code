#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#define INPUTFILE "../input"

bool unique(std::string & str);

int main()
{
    std::ifstream file(INPUTFILE);
    if (!file.is_open())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    int counter = 0;

    for (std::string buff ; getline(file, buff) ; )
    {
        std::string temp = buff.substr(buff.find_first_of('|')+2, buff.size() - buff.find_first_of('|'));
        std::string temp2;
        
        std::stringstream check(temp);
        while(getline(check, temp2, ' '))
            if (unique(temp2)) ++counter;
    }        
    
    std::cout << counter << std::endl;
}

bool unique(std::string & str)
{
    std::vector<int> lengths{2,4,3,7};
    int size = static_cast<int>(str.size());

    for (auto s : lengths)
        if (s == size)
            return true;

    return false;
}