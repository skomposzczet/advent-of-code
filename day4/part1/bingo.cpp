#include "bingo.hpp"


void Bingo::add_nums(std::string str)
{
    Board::extract_ints(str, numbers, ',');
}