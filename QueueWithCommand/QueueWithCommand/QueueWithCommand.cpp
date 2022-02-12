#include <iostream>
#include <vector>
#include <string>

int main() {

	std::size_t Q{ 0 }, cnt{ 0 };
	int k{ 0 };

	std::cin >> Q;

	std::vector<bool> queue(0);
	std::vector<std::size_t> count(0);
	//std::vector<std::string> in();

	for (std::size_t i = 0; i < Q; ++i)
	{
		std::string s;

		std::cin >> s;

		if (s == "WORRY") // WORRY i : пометить i - го человека с начала очереди как беспокоящегося;
		{
			std::cin >> k;
			queue[k] = true;
		}
		if (s == "QUIET") // QUIET i : пометить i - го человека как успокоившегося;
		{
			std::cin >> k;
			queue[k] = false;
		}
		if (s == "COME") // COME k : добавить/убрать k спокойных человек в конец очереди;
		{
			std::cin >> k;
			if (k >= 0)
				for (std::size_t m = 0; m < k; ++m)
					queue.push_back(false);
			else
				for (std::size_t m = 0; m < (-k); ++m)
					queue.pop_back();

		}
		if (s == "WORRY_COUNT") //WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
		{
			cnt = 0;
			for (auto b : queue)
				if (b) ++cnt;
			count.push_back(cnt);
		}
	}

	for (auto str : count)
		std::cout << str << '\n';

	return 0;
} 
