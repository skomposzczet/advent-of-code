#include "ventList.hpp"


void VentList::add_line(std::string str)
{
    Line temp(str);
    lines.push_back(temp);

    maxx = max(maxx, temp.x1);
    maxx = max(maxx, temp.x2);
    maxy = max(maxy, temp.y1);
    maxy = max(maxy, temp.y2);
}

void VentList::make_grid()
{
    ++maxx;
    ++maxy;
    grid = std::vector<int>(maxy*maxx, 0);

    std::for_each(lines.begin(), lines.end(), [this](Line & l){ppg(l);});
}

void VentList::ppg(Line & l)
{
    if (l.x1 == l.x2)
    {
        int b, e;
        if (l.y1 < l.y2)
        {
            b = l.y1;
            e = l.y2;
        }
        else
        {
            b = l.y2;
            e = l.y1;
        }
        for (int i = b ; i <= e ; i++)
            grid.at(i*maxy + l.x1)++;
    }
    else if (l.y2 == l.y1)
    {
        int b, e;
        if (l.x1 < l.x2)
        {
            b = l.x1;
            e = l.x2;
        }
        else
        {
            b = l.x2;
            e = l.x1;
        }
        for (int i = b ; i <= e ; i++)
            grid.at(l.y1*maxy + i)++;
    }
    else
    {
        int wy = l.y1;
        int wx = l.x1;

        int xdelta = (l.x1 < l.x2 ? 1 : -1);
        int ydelta = (l.y1 < l.y2 ? 1 : -1);

        while(wx != (l.x2+xdelta))
        {
            grid.at(wy*maxy + wx)++;
            wx+=xdelta;
            wy+=ydelta;
        }
    }
}

int VentList::result()
{
    return std::count_if(grid.begin(), grid.end(), [](int & n){return (n > 1); });
}