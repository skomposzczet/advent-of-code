#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

#define INPUTFILE "../input"

int mean(std::vector<double> & nums);
int calc(std::vector<double> & pos, int target);
int abs(int n) {return (n>0?n:-n);}
/// Calculates usage of fuel between point A and B where @p way is distance between them
int fuel(int way);

int main()
{
    std::ifstream file(INPUTFILE);
    if (!file.is_open())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    std::string buff;
    getline(file, buff);
    std::replace(buff.begin(), buff.end(), ',', ' ');

    std::istringstream iss(buff);
    int temp;
    std::vector<double> positions; 
    while(iss>>temp)
        positions.push_back(temp);

    std::cout << calc(positions, mean(positions)) << std::endl;
}

int mean(std::vector<double> & nums)
{
    return (std::accumulate(nums.begin(), nums.end(), .0) / nums.size());
}

int calc(std::vector<double> & pos, int target)
{
    int res = 0;
    std::for_each(pos.begin(), pos.end(), [&res, &target](int n){res+=fuel(abs(n-target));} );
    return res;
}

int fuel(int way)
{
    int sum = 0;
    for (int i = 1 ; i <= way ; i++)
    {
        sum+=i;
    }
    return sum;
}