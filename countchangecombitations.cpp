#include<iostream>
#include<vector>
#include<set>
using namespace std;
unsigned long long  dp(const unsigned int money,const std::vector<unsigned int>& coins)
{
     std::vector<unsigned long long > combin(money+1,0);
     combin[0]=1;
     for(auto& coin:coins)
     {
       for(unsigned int i=coin;i<=money;i++)
       combin[i]+=combin[i-coin];
     }
     return combin[money];
}
unsigned long long countChange(const unsigned int money,const std::vector<unsigned int>& coins)
{
  return dp(money,coins);
}

