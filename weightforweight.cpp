#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
int get_weight(std::string& str)
{
  int result=0;
  for(auto& it:str) result+=it-'0';
  return result;
}
std::string orderWeight(const std::string& strng)
{
 std::string result;
 std::vector<std::pair<std::string,int>> weight;
 for(int i=0;i<strng.length();i++)
 {
   std::string str;
   while(i<strng.length()&&strng[i]!=' ')
   {
     str+=strng[i];
     i++;
   }
   if(str.length()==0) return "";
   weight.emplace_back(std::pair<std::string,int>(str,get_weight(str)));
 }
 sort(weight.begin(),weight.end(),[](std::pair<std::string,int>& pair1,std::pair<std::string,int>& pair2)
 {
   if(pair1.second==pair2.second) return pair1.first<pair2.first;
   return pair1.second<pair2.second;
   });
 for(auto& it:weight) result+=(it.first+' ');
 result.pop_back();
 return result;
}
int main()
{
 std::string s="50 20";
 std::cout<< orderWeight(s)<<std::endl;
}
