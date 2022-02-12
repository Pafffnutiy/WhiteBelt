#include <iostream>
#include <vector>

std::vector<std::size_t> KnownFacs(100, 1);


long long Factorial(long long x)
{
    try
    {
        if (x < 0) throw -1;

        if ( (x == 0) || (x == 1) ) return KnownFacs[0]; // Факториал нуля и единицы

        if (KnownFacs[x] != 1) return KnownFacs[x]; // Проверяем, были ли ранее посчитан факториал числа x

        long long index{ x };

        while ((KnownFacs[index] == 1)&&(index!=1))
            --index;

        ++index;

        for (index; index <= x; ++index)
        {
            KnownFacs[index] = KnownFacs[index - 1] * index;
        }

        return KnownFacs[x];
    }
    catch (...) { std::cerr << "Factorial of negative number "; return x; }
}

/*int main()
{
    std::cout << Factorial(1)<<'\n';
    std::cout << Factorial(-2)<<'\n';
    std::cout << Factorial(6)<<'\n';
    std::cout << Factorial(5)<<'\n';
}*/