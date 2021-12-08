#include "entry.hpp"

int Entry::sum = 0;

void Entry::getdata(const std::string & str)
{
    std::vector<std::string> temp;
    tokenize(str.substr(0, str.find_first_of('|')-1), temp);
    tokenize(str.substr(str.find_first_of('|')+2, str.size() - str.find_first_of('|')), code);

    analyze(temp);
    decode();
}

void Entry::tokenize(const std::string & str, std::vector<std::string> & v)
{
    std::string temp;
    std::stringstream ss{str};
    while(getline(ss, temp, ' '))
    {
        std::sort(temp.begin(), temp.end());
        v.push_back(temp);
    }
}

void Entry::analyze(std::vector<std::string> & mappings)
{
    std::vector<std::string> six;
    six.reserve(3);
    std::vector<std::string> five;
    five.reserve(3);

    for (auto pattern : mappings)
    {
        if (pattern.size() == 2)
            patterns.at(1) = pattern;
        else if (pattern.size() == 3)
            patterns.at(7) = pattern;
        else if (pattern.size() == 4)
            patterns.at(4) = pattern;
        else if (pattern.size() == 7)
            patterns.at(8) = pattern;
        else if (pattern.size() == 6)
            six.push_back(pattern);
        else if (pattern.size() == 5)
            five.push_back(pattern);
    }

    for (auto pattern : six)
    {
        if (common(pattern, patterns.at(4)) == 4)
            patterns.at(9) = pattern;
        else if (common(pattern, patterns.at(1)) == 2)
            patterns.at(0) = pattern;
        else
            patterns.at(6) = pattern;
    }

    for (auto pattern : five)
    {
        if (common(pattern, patterns.at(1)) == 2)
            patterns.at(3) = pattern;
        else if(common(pattern, patterns.at(4)) == 3)
            patterns.at(5) = pattern;
        else
            patterns.at(2) = pattern;
    }

}

int Entry::common(const std::string & str1, const std::string & str2)
{
    int comm = 0;
    std::for_each(str1.begin(), str1.end(), [&str2, &comm](char c){if (str2.find(c) != std::string::npos) comm++; });
    return comm;
}

void Entry::decode()
{
    int part;
    std::for_each(code.begin(), code.end(), [this, &part](std::string key)
    {
        auto it = std::find(patterns.begin(), patterns.end(), key);
        if (it != patterns.end())
        {
            int ni = it-patterns.begin();
            part = part*10 + ni;
        }
    }
    );

    sum+=part;
    code = std::vector<std::string>();
    code.reserve(4);
}