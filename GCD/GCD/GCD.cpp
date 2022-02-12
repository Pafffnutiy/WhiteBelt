#include <iostream>

int GCD(std::size_t a, std::size_t b)
{
    int result{ 1 };

    while (a!=b) 
    {
        if ((a % 2 == 0) && (b % 2 == 0)) { result <<= 1; a >>= 1; b >>= 1; continue; }
        if ((a % 2 == 0) && (b % 2 != 0)) { a >>= 1; continue; }
        if ((a % 2 != 0) && (b % 2 == 0)) { b >>= 1; continue; }
        if ((a % 2 != 0) && (b % 2 != 0)) 
        {
            if (a > b) { a -= b; }
            if (a < b) { b -= a; }
            continue;
        }
    }
    result *= a;
    return result;
}

int main()
{
    std::size_t a{ 1 }, b{ 1 };
    std::cin >> a >> b;
    std::cout<<GCD(a,b);
}
