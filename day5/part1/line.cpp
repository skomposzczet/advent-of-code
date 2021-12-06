#include "line.hpp"

Line::Line(std::string str)
{
    // for (unsigned i = 0 ; i < str.size() ; i++)
    // {
    //     // if (i+1 == str.size() || isnum(str.at(i+1)) == false)
    //     // {
    //     //     temp.push_back(std::stoi(str.substr(begin, i-begin+1)));
    //     //     begin = i;
    //     // }
    //     if ( isnum(str.at(i)) )

    // }
    int begin = 0;
    int end = str.find_first_of(',');
    x1 = std::stoi(str.substr(begin, end-begin));
    
    begin = end+1;
    end = str.find_first_of(' ');
    y1 = std::stoi(str.substr(begin, end-begin));

    begin = str.find_last_of(' ') + 1;
    end = str.find_last_of(',');
    x2 = std::stoi(str.substr(begin, end-begin));

    begin = end+1;
    end = str.size();
    y2 = std::stoi(str.substr(begin, end-begin));

}