#include "cave.hpp"

void Cave::add_line(std::string line)
{
    if (!line.empty())
        grid.push_back(line);
}

void Cave::make_grid()
{
    end.setx(grid.at(0).size()-1);
    end.sety(grid.size()-1);
}

int Cave::find_path(Point starting_point, int current_total)
{
    if (starting_point == end)
        return current_total;
    
    current_total += (value(starting_point)-48);

    std::vector<Point> min;

    for (auto & v : neighbours)
    {
        if (min.empty() || ( range(starting_point+v) && value(min.at(0)) > value(starting_point+v) ) )
            min = std::vector<Point>{v};
        else if ( range(starting_point+v) && value(min.at(0)) == value(starting_point+v) )
            min.push_back(v);
    }
    // Point min{starting_point};
    // for (auto & v : neighbours)
    //     if (min == starting_point || ( range(starting_point+v) && value(min) > value(starting_point+v) ) )
    //         min = v; 
    std::vector<int> results;
    for (auto & v : min)
        results.push_back(find_path(starting_point+v, current_total));
    std::sort(results.begin(), results.end());
    
    return results.at(0);
}

int Cave::value(const Point & p) const
{
    return grid.at(p.gety()).at(p.getx()); 
}

bool Cave::range(const Point & p) const
{
    return (p.gety() <= end.gety() && p.getx() <= end.getx());
}