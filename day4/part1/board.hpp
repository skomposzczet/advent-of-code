#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>

class Board
{
friend class Bingo;
public:
    Board();

    /// Converts string @p str to row of numbers 
    void add_row(std::string str);

    /// Clears board
    void clear() { rc.clear(); rc.reserve(size*size); }

    /// Prints nums on board (debugging purposes)
    void print()const;

    /// Marks all appearances of @p num
    void add_num(int num);

    /// Checks if board is winning one
    bool check() const;

    /// Returns result from winning board
    int calc() const;

private:
    /// const val, size of board: size x size
    enum s{size = 5};
    /// Each number on board, bool indicates if number is marked
    std::vector<std::pair<int, bool>> rc;

    /// Proccesses string @p str to set of ints to @p nums, each num in string is divided form other by @p divider
    static void extract_ints(std::string & str, std::vector<int> & nums, char divider = ' ');
    /// Removes double spaces and spaces from beginning of string @p str
    static void parse(std::string & str);
};

#endif
