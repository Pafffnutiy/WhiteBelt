/*
* 
* учет изменения имени и фамилии для человека
* 
* 
*/

#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

std::string operator+ (const std::string& str, const std::vector<std::string>& vec)
{
    std::string result = str;
    //vec.pop_back();
    if (vec.size() != 0)
    {
        result += " (";
        result += vec[0];
        for (std::size_t i{ 1 }; i < vec.size(); ++i)
        {
            result += (", " + vec[i]);
        }
        result += ") ";
    }
    else { result += " "; }
    return result;
}

class Person {
public:
    Person() = default;
    Person(const std::string& n, const std::string& s, const int& y)
    {
        List[y].first = n;
        List[y].second = s;
        Year_of_birthday = y;
    }
    void ChangeFirstName(int year, const std::string& first_name) {
        if (year >= Year_of_birthday)
        {
            std::string name;
            for (const auto& p : List)
            {
                if (p.first <= year) {
                    if ((p.second).first != "") { name = (p.second).first; }
                }
            }

            if (first_name != name) List[year].first = (first_name);
        }
        // добавить факт изменения имени на first_name в год year
    }
    void ChangeLastName(int year, const std::string& last_name) {
        if (year >= Year_of_birthday)
        {
            std::string surname;
            for (const auto& p : List)
            {
                if (p.first <= year) {
                    if ((p.second).second != "") { surname = (p.second).second; }
                }
            }

            if (last_name != surname) List[year].second = (last_name);

            //List[year][1] = last_name;
            // добавить факт изменения фамилии на last_name в год year
        }
    }
    std::string GetFullName(int year) const {

        if (year < Year_of_birthday) return "No person";
        std::string name, surname;
        std::size_t cnt{ 0 };
        std::map<int, std::pair<std::string, std::string>> CopyList(List);

        for (const auto& p : List)
        {
            if (p.first == year) { break; }
            else { ++cnt; }
        }
        if (cnt != List.size()) {

            if ((CopyList[year].second != "") && (CopyList[year].first != ""))
            {
                name = CopyList[year].first;
                surname = CopyList[year].second;
                return (name + " " + surname);
            }
            if ((CopyList[year].first == "") && (CopyList[year].second != ""))
            {
                surname = CopyList[year].second;
                for (const auto& p : List)
                {
                    if (((p.second).first != "") && (year > p.first)) name = (p.second).first;
                }

                if (name == "") { return (surname + " with unknown first name"); }
            }

            if ((CopyList[year].second == "") && (CopyList[year].first != ""))
            {
                name = CopyList[year].first;
                for (const auto& p : List)
                {
                    if (((p.second).second != "") && (year > p.first)) surname = (p.second).second;
                }
                if (surname == "") { return (name + " with unknown last name"); }
            }



            return (name + " " + surname);
            // получить имя и фамилию по состоянию на конец года year
        }
        else {
            for (const auto& lol : List)
            {
                if (year > lol.first) {
                    if ((lol.second).first != "") name = (lol.second).first;
                    if ((lol.second).second != "") surname = (lol.second).second;
                }
            }

            if ((name == "") && (surname == "")) { return "Incognito"; }
            if ((name == "") && (surname != "")) { return (surname + " with unknown first name"); }
            if ((name != "") && (surname == "")) { return (name + " with unknown last name"); }
            if ((name != "") && (surname != "")) { return (name + " " + surname); }
        }
    }

    std::string GetFullNameWithHistory(int year) const {
        if (year < Year_of_birthday) return "No person";
        std::map<int, std::pair<std::string, std::string>> CopyList(List);
        std::string name, surname;
        std::vector<std::string> Name_History, Surname_History;
        std::size_t Cnt_for_name{ 0 }, Cnt_for_Surname{ 0 };
        for (const auto& p : List)
        {
            if (p.first <= year) {
                if ((p.second).first != "") { name = (p.second).first; }
                else { ++Cnt_for_name; }
                if ((p.second).second != "") { surname = (p.second).second; }
                else { ++Cnt_for_Surname; }
            } else { ++Cnt_for_Surname; ++Cnt_for_name; }
        }

        if ((Cnt_for_name == List.size()) && (Cnt_for_Surname != List.size())) { name = "with unknown first name"; }
        if ((Cnt_for_Surname == List.size()) && (Cnt_for_name != List.size())) { surname = "with unknown last name"; }
        if ((Cnt_for_Surname == List.size()) && (Cnt_for_name == List.size())) { name = "Incognito"; }

        std::string Current_Name;
        //Чистка повторов имен
        for (auto& p : CopyList)
        {
            if ((p.second).first == Current_Name)
                { (p.second).first = "" ; }
            else if(p.second.first != "") { Current_Name = (p.second).first; }
        }

         //Чистка повторов фамилий
        std::string Current_Surname;
        for (auto& p : CopyList)
        {
            if ((p.second).second == Current_Surname)
            {
                (p.second).second = "";
            }
            else if (p.second.second!="") { Current_Surname = (p.second).second; }
        }


        /*
        for (auto iter = List.begin(); iter != List.end(); ++iter)
        {
            if ((iter != List.begin()) && ((iter->second).first == ((iter--)->second).first))
            {
                ++iter;
                (iter->second).first = "";
            }
            else { ++iter; }
        }

       
        for (auto iter = List.begin(); iter != List.end(); ++iter)
        {
            if ((iter != List.begin()) && ((iter->second).second == ((iter--)->second).second))
            {
                ++iter;
                (iter->second).second = "";
            }
            else { ++iter; }
        }*/

        for (const auto& p : CopyList)
        {
            if (p.first <= year)
            {
                if (((p.second).first != "") && (1/*(p.second).first != name*/)) { Name_History.push_back((p.second).first); }
                if (((p.second).second != "") && (1/*((p.second).second != surname)*/)) { Surname_History.push_back((p.second).second); }
            }
        }
        
       if (Name_History.size() != 0) { Name_History.pop_back(); }
       if (Surname_History.size() != 0) { Surname_History.pop_back(); }


        //Surname_History.pop_back();*/

        std::reverse(begin(Name_History), end(Name_History));
        std::reverse(begin(Surname_History), end(Surname_History));

        std::string res;

        if (name == "Incognito") { res = name; }
        if (name == "with unknown first name") {
            if (Surname_History.size() != 0) {res = surname + Surname_History + name; }
            else {res = surname + " " + name;}
        }

        if (surname == "with unknown last name") { 
            if (Name_History.size() != 0) { res = name + Name_History + surname; }
            else { res = name + " " + surname; }        
        }
        if ((name != "with unknown first name") && (surname != "with unknown last name") && (name!="Incognito")) 
            { res = name + Name_History + surname + Surname_History; }

        // получить все имена и фамилии по состоянию на конец года year
        if(res[res.size()-1]==' ') res.pop_back();
        return (res);
    }

private:
    /*std::string First_name;
    std::string Second_name;*/
    // приватные поля
    std::map < int, std::pair<std::string, std::string> > List;
    int Year_of_birthday;
    //std::string CurrentName, CurrentSurname;

};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    return 0;
}


/*int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    std::cout << person.GetFullNameWithHistory(1990) << std::endl;

    person.ChangeFirstName(1966, "Pauline");
    std::cout << person.GetFullNameWithHistory(1966) << std::endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    std::cout << person.GetFullNameWithHistory(1967) << std::endl;

    return 0;
}*/

/*int main() {
    Person person;

    person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    std::cout << person.GetFullNameWithHistory(1940) << std::endl;

    return 0;
}*/

/*int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeFirstName(1965, "Appolinaria");

    person.ChangeLastName(1965, "Sergeeva");
    person.ChangeLastName(1965, "Volkova");
    person.ChangeLastName(1965, "Volkova-Sergeeva");

    for (int year : {1964, 1965, 1966}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    return 0;
}*/