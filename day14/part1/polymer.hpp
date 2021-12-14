#ifndef __POLYMER_H__
#define __POLYMER_H__

#include <string>
#include <vector>
#include <algorithm>
#include <map>

class Polymer
{
public:
    /// Initialized with polymer template
    Polymer(std::string ptemp) : ptemplate{ptemp} {}

    /// Adds insertion rule
    void add_pair(std::string line);

    /// Insert all fitting pairs
    void insert(int n);

    /// Returns final result
    int result() const;

private:
    mutable std::string letters;
    std::string ptemplate;

    std::vector<std::pair<std::string, char>> insertions;

    void insert();

    static void find_substr(std::vector<int> & vec, std::string haystack, std::string needle);
};

#endif