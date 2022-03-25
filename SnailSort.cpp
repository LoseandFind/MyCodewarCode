#include<iostream>
#include<vector>
void Snail(std::vector<int>& result,std::vector<std::vector<int>> map,std::vector<std::vector<int>>& flag,int x,int y,int len)
{
	result.emplace_back(map[x][y]);
	flag[x][y]=1;
	if(y+1<len&&flag[x][y+1]==0)//right first
	{
	     if(x-1>=0&&flag[x-1][y]==0) Snail(result,map,flag,x-1,y,len);
	     else Snail(result,map,flag,x,y+1,len);
	}
	if(x+1<len&&flag[x+1][y]==0) // down next
	{
		Snail(result,map,flag,x+1,y,len);
	}
	if(y-1>=0&&flag[x][y-1]==0) //left
	{
		Snail(result,map,flag,x,y-1,len);
	}
	if(x-1>=0&&flag[x-1][y]==0) //up lsat
	{
		Snail(result,map,flag,x-1,y,len);
	}
}
std::vector<int> snail(const std::vector<std::vector<int>> &snail_map)
{
 std::vector<int> result; 
if(snail_map[0].size()==0) return {};
int len=snail_map.size();
std::vector<std::vector<int>> flag;
for(int i=0;i<len;i++)
{
    std::vector<int> v1(len,0);
    flag.emplace_back(v1);
}
Snail(result,snail_map,flag,0,0,len);
return result;
}
int main()
{
	std::vector<std::vector<int>> snail_map={{1,2,3},{4,5,6},{7,8,9}};//can chage by yourself;
	std::vector<int> result;
	result=snail(snail_map);
	for(auto it:result)
	{
		std::cout<<it<<" ";
	}
}