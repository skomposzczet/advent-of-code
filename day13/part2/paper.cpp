#include "paper.hpp"

void Paper::get_line(std::string line)
{
    if (line.empty())
        return; 

    if (line.at(0) == 'f')
    {
        int temp = std::stoi(line.substr(line.find_first_of('=')+1, line.size()-line.find_first_of('=')-1));
        line.at(line.find_first_of('=')-1) == 'x' ? foldx(temp) : foldy(temp); 
    }
    else
    {
        int x = std::stoi(line.substr(0, line.find_first_of(',')));
        int y = std::stoi(line.substr(line.find_first_of(',')+1, line.size()-line.find_first_of(',')-1));
        
        points.emplace_back(x,y);
    }
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

void Paper::result() const
{
    int xmax = 0;
    int ymax = 0;
    std::for_each(points.begin(), points.end(), [&ymax, &xmax](Point p){if(p.getx()>xmax)xmax=p.getx();if(p.gety()>ymax)ymax=p.gety();});

    for (int y = 0 ; y <= ymax ; y++) // equals because ymax and xmax are max INDEXES
    {
        for (int x = 0 ; x <= xmax ; ++x)
            std::cout << (std::find(points.begin(), points.end(), Point(x,y)) == points.end() ? " " : "#");
                
        std::cout << "\n";             
    }
}