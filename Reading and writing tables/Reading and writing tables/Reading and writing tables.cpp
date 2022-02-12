/*#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> string2vec(std::string s)
{
    std::vector<int> vec;
    std::string str;
    
    for (const auto& c : s)
    {
        if (c != ',')
        {
            str += c;
        }
        else { vec.push_back(std::stoi(str)); str = ""; }
    }
    vec.push_back(std::stoi(str));
    return vec;    
}

std::ostream& operator<< (std::ostream& o, std::vector<int> nums)
{
    for (const auto& a : nums)
    {
        if (a != nums[nums.size() - 1]) { o << std::setw(10) << a << ' '; }
        else { o << std::setw(10) << a; }
    }
    return o;
}

std::ofstream& operator<< (std::ofstream& o, std::vector<int> nums)
{
    for (const auto& a : nums)
    {
        if (a != nums[nums.size() - 1]) { o << std::setw(10) << a << ' '; }
        else { o << std::setw(10) << a; }
    }
    return o;
}

int main()
{
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    std::size_t M{ 0 }, N{ 0 };
    input >> M >> N;
    input.ignore(1);

    char ch;
    std::string str;

    for (std::size_t i{ 0 }; i < M; ++i)
    {
        std::vector<int> nums;
        std::getline(input, str);
        nums = string2vec(str);
        if (i != M - 1) { output << nums /*<< ' ' << '\n'; }
        else { output << nums; }
    }

    input.close();
    output.close();
    return 0;
}*/

#include <iostream>
#include <iomanip>
#include <fstream>

int main()
{
    std::ifstream input("input.txt");
    std::size_t M{ 0 }, N{ 0 };
    input >> M >> N;

    for (std::size_t i{ 0 }; i < M; ++i)
    {
        for (std::size_t j{ 0 }; j < N; ++j)
        {
            int tempint;
            input >> tempint;
            if (j != N - 1) { std::cout << std::setw(10) << tempint << ' '; }
            else { std::cout << std::setw(10) << tempint; }
            input.ignore();
        }
        if (i != M - 1) { std::cout << '\n'; }
    }


    




}