#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N{ 0 };
    std::cin >> N;
    std::vector<bool> bin;
    while (N != 0)
    {
        bin.push_back(N % 2);
        N >>= 1;
    }
    std::reverse(bin.begin(),bin.end());
    
    for (auto a : bin)
    {
        std::cout << a;
    }
    return 0;
}
