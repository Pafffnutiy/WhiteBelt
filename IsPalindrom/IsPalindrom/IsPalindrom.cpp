#include <iostream>
#include <string>

bool isPalindrom(std::string s)
{
    int cnt{ 0 };
    if (s == "") return true;
    if (s.size() == 1) return true;
    for (int i = 1; i <(1+s.size() / 2); ++i)
    {
        if (s[i-1] == s[s.size()-i]) { ++cnt; }
    }
    if (cnt == s.size() / 2) return true; else return false;
}

int main()
{
    std::cout << isPalindrom("madam")<<'\n';
    std::cout << isPalindrom("gentlemen")<<'\n';
    std::cout << isPalindrom("X")<<'\n';
    std::cout << isPalindrom("")<<'\n';
    return 0;
}