#include<iostream>
#include<vector>
#include<string>

void Reverse(std::vector<int>& v)
{
	int razmer = v.size();
	for (int i = 0; i<razmer; ++i)
		v.push_back(v[i]);
	for (int i = 1; i < v.size() / 2+1; ++i)
		v[i-1] = v[v.size() - i];
	for (int i = 0; i < razmer; ++i)
		v.pop_back();

}

std::vector<int> Reversed(const std::vector<int>& v)
{
	std::vector<int> result = v;
	Reverse(result);
	return result;
}

int main()
{
	std::vector<int> numbers = { 1, 5, 3, 4, 2 };
	std::vector<int> numbers1 = Reversed(numbers);
	for (auto w : numbers1)
		std::cout << w;
}