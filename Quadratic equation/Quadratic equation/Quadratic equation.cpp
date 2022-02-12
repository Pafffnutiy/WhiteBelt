#include <iostream>
#include <cmath>

double discriminant(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

int main()
{
    double A{ 0.0 }, B{ 0.0 }, C{ 0.0 }, x1{ 0.0 }, x2{0.0};

    std::cin >> A >> B >> C;

    if (A == 0.0)
    {
        if (B != 0) {
            x1 = -C / B;
            x2 = -C / B;
        }
        else {
            std::cout << ""; std::exit(0);
        }
    }
    else
    {
        double D = discriminant(A, B, C);
        if (D >= 0) {
            x1 = (-B + std::sqrt(D)) / (2 * A);
            x2 = (-B - std::sqrt(D)) / (2 * A);
        }
        else { std::cout << ""; std::exit(0); }
    }


    if (x1 == x2)
    {
        std::cout << x1;
    }
    else {
        std::cout << x1 << ' ' << x2;
    }
}