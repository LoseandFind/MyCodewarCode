#include<iostream>
#include<vector>
static std::vector<int> number={0,1,1,2,3,3};
void CreateNumber(int n,std::vector<int>& number)
{
   for(int i=6;i<=n;i++)
      number.emplace_back(number[i-number[i-1]]+number[i-number[i-2]]);
}
int lengthSupUk(int n,int k)
{
   int result=0;
   if(n>number.size()-1) CreateNumber(n,number);
   for(int i=1;i<=n;i++)
   if(number[i]>=k) result++;
   return result;
}
int comp(int n)
{
   int result=0;
   for(int i=1;i<n;i++)
   if(number[i]>number[i+1]) result++;
   return result;
}
int main()
{
  std::cout<<lengthSupUk(3332, 973)<<std::endl;
  for(auto it:number) std::cout<<it<<" ";
  std::cout<<std::endl;
  std::cout<<comp(2)<<std::endl;
}
