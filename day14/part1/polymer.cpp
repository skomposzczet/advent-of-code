#include "polymer.hpp"

void Polymer::add_pair(std::string line)
{
    if (line.empty())
        return;

    insertions.emplace_back(line.substr(0,2), line.back());
    return;
}

void Polymer::insert(int n)
{
    while(n--)
        insert();
}

void Polymer::insert()
{
    std::string newpt = ptemplate;
    std::map<int, char> inserts;

    for (auto p : insertions)
    {
        std::vector<int> idxs;
        find_substr(idxs, ptemplate, p.first);

        for (auto idx : idxs)
            inserts[idx+1] = p.second;
    }

    std::for_each(inserts.rbegin(), inserts.rend(), [&newpt](auto m){newpt.insert(newpt.begin()+m.first, m.second);});
    ptemplate.swap(newpt);
}

int Polymer::result() const
{
    for (auto c : ptemplate)
    {
        if (std::find(letters.begin(), letters.end(), c) == letters.end())
            letters.push_back(c);
    }

    std::vector<int> counter;
    counter.reserve(4);
    for (auto c : letters)
        counter.push_back(std::count(ptemplate.begin(), ptemplate.end(), c));

    std::sort(counter.begin(), counter.end());

    return counter.back() - counter.at(0);
}

void Polymer::find_substr(std::vector<int> & vec, std::string haystack, std::string needle)
{
    auto position = haystack.find(needle);
    while(position != std::string::npos)
    {
        vec.push_back(position);
        position = haystack.find(needle, position+1);
    }
}