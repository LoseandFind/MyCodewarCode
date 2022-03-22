#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
void Number(unordered_map<string,int>& Myhash)
{
	Myhash.emplace(pair<string,int>("I",1));
	Myhash.emplace(pair<string, int>("IV", 4));
	Myhash.emplace(pair<string, int>("V", 5));
	Myhash.emplace(pair<string, int>("X", 10));
	Myhash.emplace(pair<string, int>("IX", 9));
	Myhash.emplace(pair<string, int>("XL", 40));
	Myhash.emplace(pair<string, int>("XC", 90));
	Myhash.emplace(pair<string, int>("L", 50));
	Myhash.emplace(pair<string, int>("C", 100));
	Myhash.emplace(pair<string, int>("CD", 400));
	Myhash.emplace(pair<string, int>("CM", 900));
	Myhash.emplace(pair<string, int>("M", 1000));
	Myhash.emplace(pair<string, int>("D", 500));
}
int main()
{
	string Roman = "MDCLXVI";
	int result = 0;
	unordered_map<string, int> Myhash;
	Number(Myhash);
	for (int i = 0; i < Roman.length();)
	{
		string str = Roman.substr(i, 2);
		if (Myhash.count(str))
		{
			auto it = Myhash.find(str);
			result += it->second;
			i += 2;
		}
		else
		{
			str =Roman.substr(i,1);
			auto it = Myhash.find(str);
			result += it->second;
			i++;
		}
	}
	cout<<result;
}