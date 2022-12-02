#include "paper.hpp"

void Paper::get_line(std::string line)
{
    if (line.empty())
        return; 

    if (line.at(0) == 'f')
    {
        if (f==-1)
        {
            f = std::stoi(line.substr(line.find_first_of('=')+1, line.size()-line.find_first_of('=')-1));
            w = line.at(line.find_first_of('=')-1);
        }

        return;
    }
    else
    {
        int x = std::stoi(line.substr(0, line.find_first_of(',')));
        int y = std::stoi(line.substr(line.find_first_of(',')+1, line.size()-line.find_first_of(',')-1));
        
        points.emplace_back(x,y);
    }
}

void Paper::fold()
{
    w == 'x' ? foldx(f) : foldy(f);
}

void Paper::foldx(int f)
{
    for (unsigned i = 0 ; i < points.size() ; ++i)
    {
        auto & p = points.at(i);

        if (p.getx() > f)
        {
            Point temp(2*f - p.getx(), p.gety());
            if (std::find(points.begin(), points.end(), temp) == points.end())
                points.push_back(temp);

            points.erase(points.begin()+i);
            i--;
        }
    }
}

void Paper::foldy(int f)
{
    for (unsigned i = 0 ; i < points.size() ; ++i)
    {
        auto & p = points.at(i);

        if (p.gety() > f)
        {
            Point temp(p.getx(), 2*f - p.gety());
            if (std::find(points.begin(), points.end(), temp) == points.end())
                points.push_back(temp);
            
            points.erase(points.begin()+i);
            --i;
        }
    }
}