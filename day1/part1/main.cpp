#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream file("input");
    if (!file.is_open())
        std::cout << "not ok" << std::endl;

    int curr, prev;
    curr = prev = -1;

    int counter = 0;

    for (std::string buff ; getline(file, buff) ; )
    {
        curr = std::stoi(buff);

        if (prev == -1)
        {
            prev = curr;
            continue;
        }

        if (curr > prev)
            counter++;
        
        prev = curr;
    }

    file.close();
    std::cout << counter << std::endl;
}