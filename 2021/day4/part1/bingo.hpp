#ifndef __BINGO_H__
#define __BINGO_H__

#include <vector>
#include <string>

#include "board.hpp"

class Bingo
{
public:
    Bingo() {}

    /// Add number to vector of "random" numbers
    void add_nums(std::string str);

    /// Adds board to vector of playing boards
    void add_board(Board b) { boards.push_back(b);}

    /// Finds winning board and returns result
    int result();

private:
    std::vector<int> numbers;

    std::vector<Board> boards;

};

#endif