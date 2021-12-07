#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

#define INPUTFILE "../input"

int median(std::vector<int> & nums);
int calc(std::vector<int> & pos, int target);
int abs(int n) {return (n>0?n:-n);}

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
    std::vector<int> positions; 
    while(iss>>temp)
        positions.push_back(temp);

    std::cout << calc(positions, median(positions)) << std::endl;
}

int median(std::vector<int> & nums)
{
    std::sort(nums.begin(), nums.end());
    if (nums.size()%2 != 0)
        return (nums.at(nums.size()/2)+nums.at(nums.size()-1))/2;
    else
        return nums.at(nums.size()/2-1);
}

int calc(std::vector<int> & pos, int target)
{
    int res = 0;
    std::for_each(pos.begin(), pos.end(), [&res, &target](int n){res+=(abs(n-target));} );
    return res;
}