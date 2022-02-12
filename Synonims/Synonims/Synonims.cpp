#include<set>
#include<map>
#include<string>
#include<iostream>

std::pair<std::string, std::string> inverse_pair(std::pair<std::string, std::string> pa)
{
	std::string temp;
	temp = pa.first;
	pa.first = pa.second;
	pa.second = temp;
	return pa;
}
std::pair<std::string, std::string> sort(std::pair<std::string, std::string> pa)
{
	return (pa.first > pa.second) ? pa : inverse_pair(pa);
}

int main()
{
	std::size_t q{ 0 };
	std::cin >> q;
	std::set < std::pair<std::string, std::string> > dictionary;
	std::map < std::string, std::size_t> synonims;

	for (std::size_t i{ 0 }; i < q; ++i)
	{
		std::string command;
		std::cin >> command;
		if (command == "ADD")
		{
			std::string word1, word2;
			std::cin >> word1 >> word2;
			auto temp = std::make_pair(word1, word2);
			auto sorted = sort(temp);


			if (dictionary.count(sorted) == 0)
			{
				++synonims[word1];
				++synonims[word2];
			}
			dictionary.insert(sorted);
		}

		if (command == "COUNT")
		{
			std::size_t cnt{ 0 };
			std::string word;
			std::cin >> word;

			std::cout << synonims[word] << '\n';

		}

		if (command == "CHECK")
		{
			std::size_t cnt{ 0 };
			std::string word1, word2;
			std::cin >> word1 >> word2;

			auto temp = sort(std::make_pair(word1, word2));

			if (dictionary.count(temp) != 0) { std::cout << "YES\n"; }
			else { std::cout << "NO\n"; }
		}

	}

	return 0;
}