#include "cavern.hpp"

void Cavern::raise(Point p)
{
    if (at(p) == 9)
    {
        at(p)++;
        for (auto v : neighbourhood)
        {
            if ( iir(v+p) )
                raise(v+p);
        }
    }
    else if (at(p) < 9)
        at(p)++;
}

int Cavern::result()
{
    iterations++;
    int flashed = 0;

    for (int y = 0 ; y < size ; y++)
        for (int x = 0 ; x < size ; x++)
            raise(Point(x,y));

    for (int y = 0 ; y < size ; y++)
    {
        for (int x = 0 ; x < size ; x++)
        {
            Point curr(x,y);
            if (at(curr) > 9)
            {
                at(curr) = 0;
                flashed++;
            }
        }
    }

    if (flashed == size*size)
        return iterations;
    else 
        return result();
}

void Cavern::add_row(std::string str)
{
    Row row;
    row.reserve(size);

    std::for_each(str.begin(), str.end(), [&row](const char & c){row.push_back(c-48);});
    grid.push_back(row);
}

bool Cavern::iir(Point p)
{
    return (p.getx() >= 0 && p.getx() < size && p.gety() >= 0 && p.gety() < size);
}