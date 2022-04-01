#include<iostream>
#include<vector>
#include<unordered_map>
static std::unordered_map<char, int> Myhash = { {'A',0},{'B',1},{'C',2},{'D',3},{'E',4},{'F',5},{'G',6} };
static std::unordered_map<char, int> RedorG = { {'R',1},{'Y',2} };
bool PlaneNumber(std::vector<std::vector<int>> location,int x,int y)
{
	int target = location[x][y];
	int number = 1;
	int left = y - 1, right = y + 1;
	while (left>=0&&location[x][left]==target)
	{
		number++;
		left--;
	}
	while (right<=6&&location[x][right]==target)
	{
		number++;
		right++;
	}
	return number >= 4 ? 1 : 0;
}
bool VerticalNumber(std::vector<std::vector<int>> location, int x, int y)
{
	int target = location[x][y];
	int number = 1;
	int up = x-1,dwn= x + 1;
	while (up>=0&&location[up][y]==target)
	{
		number++;
		up--;
	}
	while (dwn<=5&&location[dwn][y]==target)
	{
		number++;
		dwn++;
	}
	return number >= 4 ? 1 : 0;
}
bool ChamferedNumber01(std::vector<std::vector<int>> location, int x, int y)
{
	int target = location[x][y];
	int number = 1;
	int x_1 = x - 1, y_1 = y + 1;
	int x_2 = x + 1, y_2 = y - 1;
	while (x_1>=0&&y_1<=6&&location[x_1][y_1]==target)
	{
		number++;
		x_1--;
		y_1++;
	}
	while (x_2 <= 5 && y_2 >=0 && location[x_2][y_2] == target)
	{
		number++;
		x_2++;
		y_2--;
	}
	return number >= 4 ? 1 : 0;
}
bool ChamferedNumber02(std::vector<std::vector<int>> location, int x, int y)
{
	int target = location[x][y];
	int number = 1;
	int x_1 = x - 1, y_1 = y - 1;
	int x_2 = x + 1, y_2 = y + 1;
	while (x_1 >= 0 && y_1 >= 0 && location[x_1][y_1] == target)
	{
		number++;
		x_1--;
		y_1--;
	}
	while (x_2 <= 5 && y_2 <= 6 && location[x_2][y_2] == target)
	{
		number++;
		x_2++;
		y_2++;
	}
	return number >= 4 ? 1 : 0;
}
std::string who_is_winner(std::vector<std::string> pieces_position_list)
{
	std::vector<std::vector<int>> location;
	for (int i = 0; i < 6; i++)
	{
		std::vector<int> v(7, 0);
		location.emplace_back(v);
	}
	for (auto it : pieces_position_list)
	{
		int start = 5;
		while (location[start][Myhash[it[0]]]!=0)
		{
			start--;
		}
		location[start][Myhash[it[0]]] = RedorG[it[2]];
		if (VerticalNumber(location, start, Myhash[it[0]]) || PlaneNumber(location, start, Myhash[it[0]]) || ChamferedNumber01(location, start, Myhash[it[0]]) || ChamferedNumber02(location, start, Myhash[it[0]]))
		{
			if (location[start][Myhash[it[0]]] == 1) return "Red";
			else return "Yellow";
		}
	}
	return "Draw";
}
int main()
{
	std::vector<std::string> list = { "A_Yellow",
				"B_Red",
				"B_Yellow",
				"C_Red",
				"G_Yellow",
				"C_Red",
				"C_Yellow",
				"D_Red",
				"G_Yellow",
				"D_Red",
				"G_Yellow",
				"D_Red",
				"F_Yellow",
				"E_Red",
				"D_Yellow"
	};
	std::cout<<who_is_winner(list);
}