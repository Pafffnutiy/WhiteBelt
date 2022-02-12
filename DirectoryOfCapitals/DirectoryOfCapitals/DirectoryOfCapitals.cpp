#include <iostream>
#include <string>
#include <map>

bool is_Exist(std::map<std::string, std::string> mymap, std::string key) {
    const auto found = mymap.find(key);
    if (found == mymap.cend())
        return 0;
    else
        return 1;;
}

void PrintMap(std::map<std::string, std::string> Map)
{
    for (const auto& str : Map)
    {
        std::cout << str.first << '/' << str.second << ' ';
    }
}

int main()
{
    std::size_t Q;
    std::cin >> Q;
    std::string command;
    std::map<std::string, std::string> Directory_of_capitals;
    for (std::size_t i{ 0 }; i < Q; ++i)
    {
        std::cin >> command;
        if (command == "CHANGE_CAPITAL") 
        {
            std::string country, new_capital;
            std::cin >> country >> new_capital;
            if (is_Exist(Directory_of_capitals, country)) {
                if (Directory_of_capitals[country] == new_capital) {
                    std::cout << "Country " << country << " hasn't changed its capital\n";
                }
                else {
                    std::cout << "Country " << country << " has changed its capital from " << Directory_of_capitals[country] << " to " << new_capital << '\n';
                    Directory_of_capitals[country] = new_capital;
                }
            } else {
                std::cout << "Introduce new country " << country << " with capital " << new_capital << '\n';
                Directory_of_capitals[country] = new_capital;
            }
        }

        if (command == "RENAME") 
        {
            std::string old_country_name, new_country_name;
            std::cin >> old_country_name >> new_country_name;
            if ((new_country_name == old_country_name) || (!is_Exist(Directory_of_capitals, old_country_name)) || (is_Exist(Directory_of_capitals, new_country_name)))
            {
                std::cout << "Incorrect rename, skip\n";
            }
            else
            {
                std::cout << "Country " << old_country_name << " with capital " << Directory_of_capitals[old_country_name] << " has been renamed to " << new_country_name <<'\n';
                std::string capital;
                capital = Directory_of_capitals[old_country_name];
                Directory_of_capitals.erase(old_country_name);
                Directory_of_capitals[new_country_name] = capital;
            }
        }

        if (command == "ABOUT") 
        {
            std::string country;
            std::cin >> country;
            if (!is_Exist(Directory_of_capitals, country)) { std::cout << "Country " << country << " doesn't exist\n"; }
            else 
            {
                std::cout << "Country " << country << " has capital " << Directory_of_capitals[country] << '\n';
            }
        }

        if (command == "DUMP") 
        {
            if (Directory_of_capitals.size() == 0) { std::cout << "There are no countries in the world\n"; }
            else { PrintMap(Directory_of_capitals); }
        }


    }
    return 0;
}
