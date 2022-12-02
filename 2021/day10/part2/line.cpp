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
                return;

            q.pop_back();
        }
    }

    line_res.push_back(0);

    std::for_each(q.rbegin(), q.rend(), [this](char c)
    {
        line_res.at(line_res.size()-1) = line_res.at(line_res.size()-1)*5 + idx(c, left)+1;
    }
    );
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

long Line::result() 
{
    std::sort(line_res.begin(), line_res.end());
    return line_res.at(line_res.size()/2);
}