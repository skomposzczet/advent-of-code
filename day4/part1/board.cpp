#include "board.hpp"

Board::Board()
{
    rc.reserve(size*size);
}

void Board::extract_ints(std::string & str, std::vector<int> & nums, char divider)
{
    int begin = 0;
    for (unsigned i = 0 ; i < str.size() ; i++)
    {
        if (str.at(i) == divider || (i+1 == str.size()))
        {
            if (i+1 == str.size()) i++;
            std::string temp = str.substr(begin, i-begin);
            nums.push_back(std::stoi(temp));
            begin = i+1;
        }

    }
}

void Board::parse(std::string & str)
{
    // std::string newstr;

    // size_t beg = 0;
    // size_t len = str.length();

    // while (beg < len)
    // {
    //     size_t end = str.find_first_of(' ', beg) + 1;
    //     newstr += str.substr(beg, end - beg);
    //     beg = str.find_first_not_of(' ', end);
    // }

    // str = newstr;

    while (str.at(0) == ' ')
        str.erase(0, 1);
        
    for (unsigned i = 0 ; i < str.size() ; i++)
    {
        if (str.at(i) == ' ' && str.at(i+1) == ' ')
            str.erase(i--, 1);
    }
}

void Board::add_row(std::string str)
{
    std::vector<int> row;
    parse(str);
    extract_ints(str, row);
    for (auto num : row)
        rc.push_back(std::make_pair(num, false));
}

void Board::print()const
{
    for (int i = 0 ;i  < size;  i++)
    {
        for (int  j = 0 ; j < size ; j ++)
            std::cout << rc.at(i*size + j).first << " ";

        std::cout << "\n";            
    }
    std::cout << "\n\n";
}