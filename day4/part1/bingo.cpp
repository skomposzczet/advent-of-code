#include "bingo.hpp"


void Bingo::add_nums(std::string str)
{
    Board::extract_ints(str, numbers, ',');
}

int Bingo::result() 
{
    // for (unsigned i = 0 ; i < numbers.size() ; i++)
    for (auto num : numbers)
    {
        // int num =  numbers.at(i);

        // std::for_each(boards.begin(), boards.begin(), [num](Board & b){ b.add_num(num); } );
        for (unsigned i = 0 ; i < boards.size() ; i++)
            boards.at(i).add_num(num);
        
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