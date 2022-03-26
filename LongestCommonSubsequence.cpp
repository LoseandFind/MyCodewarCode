#include<iostream>
#include<string>
#include<vector>
using namespace std;
string lcs(const string& x,const string& y)
{
	string result;
	vector<vector<int>> flag;
	for(int i=0;i<=y.length();i++)
	{
	    vector<int> v(x.length()+1,0);
	    flag.emplace_back(v);
	}
	int len1=flag.size();
	int len2=flag[0].size();
	for(int i=1;i<len1;i++)
	{
	   for(int j=1;j<len2;j++)
	   {
		if(x[j-1]==y[i-1]) flag[i][j]=flag[i-1][j-1]+1;
		else
		{
		    if(flag[i-1][j]>=flag[i][j-1]) flag[i][j]=flag[i-1][j];
		    else flag[i][j]=flag[i][j-1];
		}
           }
	}
	len1--;
	len2--;
	while(flag[len1][len2]!=0)
	{
	   if(flag[len1][len2]==flag[len1-1][len2-1]+1){ result=y[len1-1]+result;len1--;len2--;}
	   else if(flag[len1][len2]==flag[len1-1][len2]) len1--;
	   else if(flag[len1][len2]==flag[len1][len2-1]) len2--;
	}
	return result;
}
int main()
{

	string x="abcdef";
	string y="acf";
	cout<<lcs(x,y);
	return 0;
}



