#include "line.hpp"

void Line::proccess_line(std::string line)
{
    std::string q;
    for (auto c : line)
    {
        if (is_left(c))
            q.push_back(c);
        else if (is_right(c))
        {
            if (!match(q.at(q.size()-1), c))
                idx_illegal.at(idx_right(c))++;

            q.pop_back();
        }
    }
}

bool Line::match(char l, char r) const
{
    int lidx, ridx;

    if (std::find(left.begin(), left.end(), l) != left.end())
        lidx = std::find(left.begin(), left.end(), l) - left.begin();
    else
        return false;

    if (std::find(right.begin(), right.end(), r) != right.end())
        ridx = std::find(right.begin(), right.end(), r) - right.begin();
    else
        return false;

    return lidx == ridx;
}

int Line::result() 
{
    for (unsigned i = 0 ; i < values.size() ; i++)
        res += idx_illegal.at(i) * values.at(i);

    return res;
}