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

    void add_row(std::string);
    void clear() { rc.clear(); rc.reserve(size*size); }
    void print()const;
    void add_num(int num);
    bool check() const;
    int calc() const;

private:
    enum s{size = 5};
    std::vector<std::pair<int, bool>> rc;

    static void extract_ints(std::string & str, std::vector<int> & nums, char divider = ' ');
    static void parse(std::string & str);
};

#endif
