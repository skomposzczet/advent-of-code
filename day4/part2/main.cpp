#include <iostream>
#include <string>
#include <fstream>

#include "bingo.hpp"
#include "board.hpp"

#define INPUTFILE "../input"

int main()
{
    std::ifstream file(INPUTFILE);
    if (!file.is_open())
    {
        std::cout << "File not found" << std::endl;
        return 1;
    }

    std::string buff;
    Bingo bingo;
    Board board;

    getline(file, buff);
    bingo.add_nums(buff);

    // space
    getline(file, buff);

    for (int i = 0 ; getline(file, buff) ; i++)
    {
        if (i == 5)
        {
            bingo.add_board(board);
            board.clear();
            i = -1;
        }
        else
            board.add_row(buff);
    }
    bingo.add_board(board);

    std::cout << bingo.result() << std::endl;

}