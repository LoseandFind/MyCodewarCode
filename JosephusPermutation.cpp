#include<iostream>
#include<vector>
#include<algorithm>
std::vector<int> josephus(std::vector<int> items, int k)
{
	std::vector<int> result;
	int length = items.size();
	int start = 0;//record the start 
	while (!items.empty())
	{
		start =(start+k - 1) % length;
		result.emplace_back(items[start]);
		items.erase(items.begin() + start);
		length--;
		if (length== 0) break;
		start = start%length;
	}
	return result;
}
int main()
{
	std::vector<int> items = {1,2,3,4,5,6,7};
	std::vector<int> result;
	result=josephus(items, 3);
	for (auto number : result)
	{
		std::cout << number << " ";
	}
}