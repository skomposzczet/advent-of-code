#include "heightmap.hpp"

void Hmap::add_row(std::string str)
{
    rows.push_back(str);
}

void Hmap::analyze()
{
    for (unsigned i = 0 ; i < rows.size() ; ++i)
    {
        for (unsigned j = 0 ; j < rows.at(i).size() ; ++j)
        {
            if (is_lowest(j,i))
            {
                res += (cti(rows.at(i).at(j))+1);
                j++;
            }
        }
    }
}

bool Hmap::is_lowest(int x, int y) const
{
    char sus = rows.at(y).at(x);

    int eq=0;
    int comps=0;

    //checking up and bot
    for (int delta = -1 ; delta < 2 ; delta+=2)
    {
        // checking if in range
        try
        {
            char temp = rows.at(y+delta).at(x);
            if (temp < sus)
                return false; 
            else if (temp == sus)
                eq++;
            
            comps++;
        }
        catch(const std::out_of_range& e) {}
        
           
    }

    // checking sides
    for (int delta = -1 ; delta < 2 ; delta+=2)
    {
        // checking if in range
        try
        {
            char temp = rows.at(y).at(x+delta);
            if (temp < sus)
                return false;
            else if (temp == sus)
                eq++;

            comps++; 
        }
        catch(const std::out_of_range& e) {}
        
    }

    if (eq==comps)
        return false;

    return true;
}