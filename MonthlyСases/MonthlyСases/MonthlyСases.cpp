#include <iostream>
#include <vector>
#include <string>
template <typename T>
T min(const T& a, const T& b)
{
    T tmp;
    (a <= b) ? (tmp = a) : (tmp = b);
    return tmp;
}

int main()
{
    std::size_t Q{ 0 }, month{ 1 };

    std::vector<std::vector<std::vector<std::string>>> cases(12);
    cases[0].resize(31);
    cases[1].resize(28);
    cases[2].resize(31);
    cases[3].resize(30);
    cases[4].resize(31);
    cases[5].resize(30);
    cases[6].resize(31);
    cases[7].resize(31);
    cases[8].resize(30);
    cases[9].resize(31);
    cases[10].resize(30);
    cases[11].resize(31);

    std::vector<std::vector<std::string>> output;

    std::cin >> Q;

    for (std::size_t i = 0; i < Q; ++i)
    {
        std::string command;
        std::cin >> command;

        if (command == "ADD")//ADD i s: Назначить дело с названием s на день i текущего месяца.
        {
            std::size_t day{ 0 };
            std::string task;
            std::cin >> day >> task;

            cases[month - 1][day-1].push_back(task);
        }

        if (command == "DUMP") //DUMP i: Вывести все дела, запланированные на день i текущего месяца.
        {
            std::size_t day;
            std::cin >> day;

            output.push_back(cases[month - 1][day - 1]);
            /*std::cout << cases[month - 1][day-1].size() << ' ';
            for (auto s : cases[month - 1][day-1])
                std::cout << s << ' ';
            std::cout << '\n';*/
        }
       
        if (command == "NEXT") //NEXT: Перейти к списку дел на новый месяц.
        {
            std::size_t sizevec;
            std::size_t temp{ 0 };
            if (month < 12) { ++month; temp = month - 2; } else { month = 1; temp = 11; }
            //if (month - 2 < 0) { temp = 11; } else { temp = month - 2; }

            sizevec = cases[temp].size();

            if (cases[month - 1].size() < cases[temp].size())
            {
                for (std::size_t t = 0; t < cases[month - 1].size(); ++t)
                    cases[month - 1][t] = cases[temp][t];
                for (std::size_t t = cases[month - 1].size(); t < cases[temp].size(); ++t)
                    for (std::size_t i = 0; i < cases[temp][t].size(); ++i)
                    {
                        cases[month - 1][cases[month - 1].size() - 1].push_back(cases[temp][t][i]);
                    }
            }
            else
            {
                std::size_t minimum{ min(cases[month - 1].size(), cases[temp].size()) };
                for (std::size_t t = 0; t < minimum; ++t)
                    cases[month - 1][t] = cases[temp][t];
            }
            cases[temp].clear();
            cases[temp].resize(sizevec);
        }
    }

    for (std::size_t i = 0; i < output.size(); ++i)
    {
        std::cout << output[i].size() << ' ';
        for (auto s : output[i])
            std::cout << s << ' ';
        std::cout << '\n';
    }
    return 0;
}
