#include<iostream>
#include<vector>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<utility>
static bool Newsort(std::pair<std::string,int> pair1,std::pair<std::string,int> pair2)
{
      if(pair1.first.length()>pair2.first.length())
      {
        return 1;
      }
      else if(pair1.first.length()==pair2.first.length())
      {
        if(pair1.second==pair2.second)  return pair1.first[0]<pair2.first[0];
        else return pair1.second<pair2.second;
      }
      return 0;
}

std::string mix(const std::string& s1,const std::string& s2)
{
  std::string result;
  std::vector<std::pair<std::string,int>> Finalvector;
  std::unordered_map<char,std::string> Hashs1;
  std::unordered_map<char,std::string> Hashs2;
  for(auto it:s1)
  {
    if(it>='a'&&it<='z')  Hashs1[it]+=it;
  }
  for(auto it:s2)
  {
    if(it>='a'&&it<='z') Hashs2[it]+=it;
  }
  for(auto strs1:Hashs1)
  {
    if(strs1.second.length()>1&&strs1.second.length()>Hashs2[strs1.first].length())
    {
      Finalvector.emplace_back(std::pair<std::string,int>(strs1.second,1));
    }
    else if(strs1.second.length()>1&&strs1.second.length()==Hashs2[strs1.first].length())
    {
      Finalvector.emplace_back(std::pair<std::string,int>(strs1.second,3));
    }
  }
  for(auto strs2:Hashs2)
  {
    if(strs2.second.length()>1&&strs2.second.length()>Hashs1[strs2.first].length())
    {
      Finalvector.emplace_back(std::pair<std::string,int>(strs2.second,2));
    }
  }
  std::sort(Finalvector.begin(),Finalvector.end(),Newsort);
  for(auto it:Finalvector)
  {
    if(it.second==1)
    {
      result+="/1:"+it.first;
    }
    else if(it.second==2)
    {
       result+="/2:"+it.first;
    }
    else  result+="/=:"+it.first;
  }
  result=result.substr(1,result.length());
  return result;
}
int main()
{
  std::string s1="Are the kids at home? aaaaa fffff";
  std::string s2="Yes they are here! aaaaa fffff";
  std::cout<<mix(s1,s2)<<std::endl;
}
