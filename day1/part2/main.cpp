#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define TREE (3)
#define INPUTFILE "../input"

class Index
{
public:
    Index() :ind{0} {}
    Index(int i) :ind{i} {}
    Index operator++()
    {
        ind = (ind+1)%TREE;
        return *this;
    }

    operator int()
    {
        return ind;
    }

    Index next() const
    {
        return (ind+1)%TREE;
    }

private:
    int ind;
};

struct Sum
{
    Sum() : s{0} {}
    int s;
    void zero() 
    { 
        s = 0;
    }
    void add(int n) 
    { 
        s+=n; 
    }
    operator int()
    {
        return s;
    }
};

int main()
{
    std::ifstream file(INPUTFILE);
    if (!file.is_open())
        std::cout << "File not found" << std::endl;

    Index index;
    std::vector<Sum> sums(3);
    std::string buff;

    const int first_comparison = 3;
    int i = 0;
    int counter = 0;

    while(getline(file, buff))
    {
        int temp = std::stoi(buff);

        sums.at(index.next()).add(temp);

        if (i >= first_comparison)
        {
            if (sums.at(index) < sums.at(index.next()))
                counter++; 
        }

        sums.at(index).zero();
        sums.at(index).add(temp);
        sums.at((index.next()).next()).add(temp);

        ++index;
        i++;
    }

    std::cout << counter << std::endl;
}