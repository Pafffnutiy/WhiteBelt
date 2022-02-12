#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name, surname;
    std::size_t date, month, year;

};

int main()
{
    std::size_t N{ 0 }, M{ 0 };
    std::cin >> N;
    std::vector<Student> Group(N);

    for (std::size_t i{ 0 }; i < N; ++i)
    {
        std::cin >> Group[i].name >> Group[i].surname >> Group[i].date >> Group[i].month >> Group[i].year;
    }

    std::cin >> M;
    for (std::size_t i{ 0 }; i < M; ++i)
    {
        std::string command;
        long num;
        std::cin >> command >> num;

        if (command == "name")
        {
            if ((num >= 1) && (num <= N))
            {
                std::cout << Group[num - 1].name << ' ' << Group[num - 1].surname << '\n';
            }
            else {
                std::cout << "bad request\n";
            }
        }

        if (command == "date")
        {
            if ((num >= 1) && (num <= N))
            {
                std::cout << Group[num - 1].date << '.' << Group[num - 1].month << '.' << Group[num - 1].year << '\n';
            }
            else { std::cout << "bad request\n";}
        } 

        if ((command != "name") && (command != "date"))
        {
            std::cout << "bad request\n";
        }
    }

}