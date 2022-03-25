#include<vector>
#include<algorithm>
#include<iostream>
unsigned long long solution(const std::vector<unsigned long long>& arr) {
	//your code here
	std::vector<unsigned long long> arr1;
	arr1 = arr;//because the arr is modified by const,so we make a new vector
	unsigned long long result = 0;
	std::sort(arr1.begin(), arr1.end());//sort the new vector first
	result = arr1[0];//arr1[0] is the smallest one,let's result equal to arr1[0]
	int len = arr1.size();
	for (int i = 1; i < len; i++)
	{
		unsigned long long small = 0;
		if (arr1[i] % result == 0)
		{
			small = arr1[i] - (arr1[i] / result - 1) * result;
		}
		else
		{
			small = arr1[i] - (arr1[i] / result) * result;
		}
		if (small == 1)//if small equal to 1,return arr1's len;
		{
			result = len * 1;
			return result;
		}
		if (result > small)
		{
			if (result % small == 0) result = small;
			else
			{
				result = result - (result / small) * small;//let's result keep smallest;
			}
		}
	}
	return result * len;
}
int main()
{
	std::vector<unsigned long long> arr = { 30,12};
	std::cout << solution(arr);
}