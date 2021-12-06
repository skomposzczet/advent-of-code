#ifndef __LINE_H_
#define __LINE_H_

#include <string>
#include <vector>

class Line
{
friend class VentList;
public:
    Line() {}

    /// Converts string to Line
    explicit Line(std::string str);


private:
    int x1;
    int y1;

    int x2;
    int y2;

    /// @returns True if char represent number in ASCII
    static bool isnum(char c) {return ( (c < '0' && c > '9') ? false : true); }
};

#endif