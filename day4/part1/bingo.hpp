#ifndef __BINGO_H__
#define __BINGO_H__

#include <vector>
#include <string>

#include "board.hpp"

class Bingo
{
public:
    Bingo() {}

    void add_nums(std::string str);
    void add_board(Board b) { boards.push_back(b);}

    int result();

private:
    std::vector<int> numbers;

    std::vector<Board> boards;

};

#endif