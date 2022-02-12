#include <iostream>
#include <vector>
#include <string>

bool IsPalindrom(std::string s)
{
    int cnt{ 0 };
    if (s == "") return true;
    if (s.size() == 1) return true;
    for (int i = 1; i < (1 + s.size() / 2); ++i)
    {
        if (s[i - 1] == s[s.size() - i]) { ++cnt; }
    }
    if (cnt == s.size() / 2) return true; else return false;
}

std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLength)
{
    std::vector<std::string> str;
    for (auto w : words)
    {
        if ((w.size() >= minLength) && (IsPalindrom(w))) { str.push_back(w); }
    }

    return str;

}


int main()
{
    std::vector<std::string> vec1 = PalindromFilter({ "abacaba", "aba" },5);
    std::vector<std::string> vec2 = PalindromFilter({ "abacaba", "aba" },2);
    std::vector<std::string> vec3 = PalindromFilter({ "weew", "bro", "code" },4);

    for (auto w1 : vec1) std::cout << w1;
    std::cout << '\n';
    for (auto w2 : vec2) std::cout << w2;
    std::cout << '\n';
    for (auto w3 : vec3) std::cout << w3;

}