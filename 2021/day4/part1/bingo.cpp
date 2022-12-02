#include "bingo.hpp"


void Bingo::add_nums(std::string str)
{
    Board::extract_ints(str, numbers, ',');
}

int Bingo::result() 
{
    for (auto num : numbers)
    {
        std::for_each(boards.begin(), boards.end(), [num](Board & b){ b.add_num(num); } );
        
        for (unsigned j = 0 ; j < boards.size() ; j++)
        {
            if (boards.at(j).check())
            {
                return boards.at(j).calc() * num;
            }
        }
    }

    return 0;
}