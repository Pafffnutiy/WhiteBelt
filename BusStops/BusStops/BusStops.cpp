#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

std::ostream& operator<<(std::ostream& o, const std::vector<std::string>& vec) {
	for (const auto& v : vec)
	{
		o << v << ' ';
	}
	return o;
}

/*sort(std::vector<std::vector<std::string>> vec_)
{
	for(const auto& w:vec_)
		vectemp.push_back
}*/

int main()
{
	size_t Q{ 0 };
	std::cin >> Q;
	std::string command;
	std::vector<std::vector<std::string>> Bus_stops;

	for (std::size_t i{ 0 }; i < Q; ++i)
	{
		std::cin >> command;

		if (command == "NEW_BUS")
		{
			std::vector<std::string> temp;
			std::string bus, stop;
			std::cin >> bus;
			temp.push_back(bus);
			std::size_t stop_count{ 0 };
			std::cin >> stop_count;
			//std::vector<std::string> stops;
			for (size_t i{ 0 }; i < stop_count; ++i)
			{
				std::cin >> stop;
				temp.push_back(stop);
			}
			Bus_stops.push_back(temp);
		}

		if (command == "BUSES_FOR_STOP")
		{
			std::string stop;
			std::vector<std::string> buses;
			std::size_t cnt{ 0 };
			std::cin >> stop;
			for (const auto& a : Bus_stops)
				for (const auto& b : a)
				{
					if (b == stop) {
						buses.push_back(a[0]);
						++cnt;
					}
				}

			if (cnt != 0) { std::cout << buses << '\n'; }
			else {
				std::cout << "No stop\n";
			}
		}

		if (command == "STOPS_FOR_BUS")
		{
			std::string bus;
			std::vector<std::string> buses;
			std::cin >> bus;
			std::size_t cnt{ 0 };
			for (const auto& k : Bus_stops)
			{
				if (k[0] != bus) { ++cnt; }
				else { break; }
			}

			if (cnt == Bus_stops.size()) { std::cout << "No bus\n"; }

			else {
				cnt = 0;
				for (const auto& b : Bus_stops)
				{
					std::size_t iter{ 0 };
					if (b[0] == bus)
					{
						for (const auto& str : b)
						{
							for (const auto& t : Bus_stops)
							{
								for (const auto& p : t)
									if (p == str) {
										if (t[0] != bus) buses.push_back(t[0]);
									}
							}
							if (iter != 0)
							{
								if (buses.size() == 0) { std::cout << "Stop " << b[iter] << ": no interchange\n"; }
								else { std::cout << "Stop " << b[iter] << ": " << buses << '\n'; }
							}
							++iter;
							buses.clear();
						}
						
					}
				}
			}
		}

		if (command == "ALL_BUSES")
		{
			std::vector<std::vector<std::string>> tempor1 = Bus_stops;
			std::sort(Bus_stops.begin(), Bus_stops.end());
			if (Bus_stops.size() != 0) {
				for (const auto& b : Bus_stops)
				{
					std::cout << "Bus " << b[0] << ": ";
					for (std::size_t i{ 1 }; i < b.size(); ++i)
						std::cout << b[i] << ' ';
					std::cout << '\n';
				}
			}
			else { std::cout << "No buses\n"; }
			Bus_stops = tempor1;
			tempor1.clear();
		}


	}


	return 0;
}