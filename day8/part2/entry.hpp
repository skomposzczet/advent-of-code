#ifndef __ENTRY_H__
#define __ENTRY_H__

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class Entry
{
public:
    Entry() : patterns{std::vector<std::string>(10)} {code.reserve(4);}
    ~Entry() {}

    /// Proccesses string from input
    void getdata(const std::string & str);

    /// Returns final result
    int result() const { return sum; }

private:
    std::vector<std::string> patterns;
    std::vector<std::string> code;

    static int sum;

    /// Tokenizes string @p str into vector @p v , sorts each string
    void tokenize(const std::string & str, std::vector<std::string> & v);

    /// Assigns correct strings to patterns
    void analyze(std::vector<std::string> & mappings);

    /// @returns number of common chars
    int common(const std::string & str1, const std::string & str2);

    /// Decodes and clears code vector
    void decode();

};

#endif