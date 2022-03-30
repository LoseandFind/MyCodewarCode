#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
using namespace std;
void Getfactor(int number,vector<int>& factor)
{
   int num=number;
   for(int i=2;i<number;i++)
   {
       if(number%i==0)
       {
	factor.emplace_back(i);
	number=number/i;
	break;
       }
   }
   if(number==num||number==0)
   {
     factor.emplace_back(num);
     return;
   }
   Getfactor(number,factor);
}
int Zeroes(int base,int number)
{
    int result=number;
    unordered_map<int,int> Myhash;
    vector<int> factors;
    Getfactor(base,factors);
    for(auto it:factors) Myhash[it]++;
    for(auto it:Myhash)
    {
       int i=1;
       int sum=0;
       while(pow(it.first,i)<=number)
       {
	   sum+=number/(pow(it.first,i));
	   i++;
       }
       sum/=it.second;
       result=min(sum,result);
    }
    return result;
}
int main()
{ 
   int base=16;
   int number=16;
   cout<<Zeroes(base,number)<<endl;
}
