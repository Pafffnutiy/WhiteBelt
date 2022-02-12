#include <iostream>
#include <string>
#include <map>

std::map<char, int> BuildCharCounters(std::string str)
{
    std::map<char, int> result;
    for (const char& ch : str)
    {
        ++result[ch];
    }
    return result;
}

int main()
{
    std::size_t N{ 0 };
    std::cin >> N;
    std::string first_word, second_word;
    for (std::size_t i{0}; i<N; ++i)
    {
        std::cin >> first_word >> second_word;

        std::map<char, int> map_first_word, map_second_word;

        map_first_word  = BuildCharCounters(first_word);
        map_second_word = BuildCharCounters(second_word);
        if (map_first_word == map_second_word) { std::cout << "YES\n"; }
        else { std::cout << "NO\n"; }
    }
    
    return 0;
}