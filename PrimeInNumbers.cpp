#include<iostream>
#include<vector>
std::string PrimeDecomp(int lst)
{
    std::string result;
    int target=lst;
    for(int i=2;i<lst;i++)
    { 
      if(target==1) break;
      int num=0;
      while(target%i==0)
      {
	 target=target/i;
	 num++;
      }
      if(num>1) result+='('+std::to_string(i)+"**"+std::to_string(num)+')';
      else if(num==1) result+='('+std::to_string(i)+')';
    }
   if(result.length()==0) result+='('+std::to_string(lst)+')';
   return result;
}
int main()
{
	std::cout<<PrimeDecomp(7775460)<<std::endl;
       return 0;	
}
