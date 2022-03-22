#include <vector>
#include<iostream>
#include<unordered_map>
int findOdd(const std::vector<int>& numbers) {
	std::unordered_map<int, int> Myhash;
	for (auto it : numbers)
	{
		Myhash[it]++;
	}
	for (auto it : Myhash) 
	{
		std::cout << it.first << " " << it.second << std::endl;
		if (it.second % 2 == 1) return it.second; 
	};
}
int main()
{
	std::vector<int> number = { 20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5 };
	std::cout << findOdd(number);
}