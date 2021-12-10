#ifndef __LINE_H__
#define __LINE_H__

#include <string>
#include <vector>
#include <algorithm>

class Line
{
public:
    Line() {}

    /// Finds unmatching brackets and increases their counter
    void proccess_line(std::string line);

    /// Chooses middle value from line_res
    long result();

private:
    // left right brackets, indexes match
    const std::string left {"([{<"};
    const std::string right{")]}>"};

    /// Results for each line
    std::vector<long> line_res;


    /// @returns True if @p l and @p r are matching brackets
    bool match(char l, char r) const;

    /// @returns True is c is left bracket
    bool is_left (char c) const {return (std::find(left.begin(), left.end(), c) != left.end());}
    
    /// @returns True is c is right bracket
    bool is_right(char c) const {return (std::find(right.begin(), right.end(), c) != right.end());}

    /// @returns Index of bracket
    int idx(char b, std::string side) { return std::find(side.begin(), side.end(), b) - side.begin(); }
    
};

#endif