#ifndef __LINE_H__
#define __LINE_H__

#include <string>
#include <vector>
#include <algorithm>

class Line
{
public:
    Line() : idx_illegal{std::vector<int>(4,0)}, res{0} {}

    /// Finds unmatching brackets and increases their counter
    void proccess_line(std::string line);

    /// Multiplies each counter by their multipliers
    int result();

private:
    // left right brackets and their values, indexes match
    const std::string left {"([{<"};
    const std::string right{")]}>"};
    const std::vector<int> values{3, 57, 1197, 25137};

    /// Counter of illegal brackets
    std::vector<int> idx_illegal;

    int res;

    /// @returns True if @p l and @p r are matching brackets
    bool match(char l, char r) const;

    /// @returns True is c is left bracket
    bool is_left (char c) const {return (std::find(left.begin(), left.end(), c) != left.end());}
    
    /// @returns True is c is right bracket
    bool is_right(char c) const {return (std::find(right.begin(), right.end(), c) != right.end());}

    /// @returns Index of right bracket
    int idx_right(char r) const {return std::find(right.begin(), right.end(), r) - right.begin(); }
    
};

#endif